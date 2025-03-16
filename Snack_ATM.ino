/*

   Demonstrates the use a 16x2 LCD display and
  4x4 LCD display.  T

   The  Arduino circuit connection for LCD:

   * LCD RS  pin to analog pin A0

   * LCD  Enable pin to analog pin A1

   * LCD D4  pin to analog pin A2

   * LCD D5  pin to analog pin A3

   * LCD D6  pin to analog pin A4

   * LCD D7  pin to analog pin A5

   The  Arduino circuit connection for MAtrix Key Pad:

   * ROW1 pin  to digital pin 5

   * ROW2 pin  to digital pin 4

   * ROW3 pin  to digital pin 3

   * ROW4 pin  to digital pin 2

   * COLUMN1  pin to digital pin 6

   * COLUMN2  pin to digital pin 7

   * COLUMN3  pin to digital pin 8

   * COLUMN4  pin to digital pin 9

   */

  // include the library code:

  #include <Keypad.h>

  #include <LiquidCrystal.h>

  //initialize the library with the numbers of theinterface pins

LiquidCrystal lcd(10, 11, 12, A2, A3, A4);

  //4x4 Matrix key pad

  const byte ROWS = 4; // Four rows

  const byte COLS = 4; // Four columns

  // Define the Keymap

  char keys[ROWS][COLS] = 

  {

   
  {'1','2','3','A'},

   
  {'4','5','6','B'},

   
  {'7','8','9','C'},

   
  {'*','0','#','D'}

  };

  // Connect keypad ROW0, ROW1, ROW2 and ROW3 toArduino pins.

  byte rowPins[ROWS] = { 5, 4, 3, 2 };

  // Connect keypad COL0, COL1, COL2 and COL3 to Arduino pins.

  byte colPins[COLS] = { 6, 7, 8, 9 }; 

  // Create the Keypad

  Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

  void setup() 

  {

    // set upthe LCD's number of columns and rows:

   
  lcd.begin(16, 2);

    // Printa message to the LCD.

  }

  void loop() 

  {

    char key= kpd.getKey();

    // setthe cursor to column 0, line 1
    lcd.setCursor(0,1);
    // (note:ine 1 is the second row, since counting begins with 0):


   
  if(key)  

    {

       // setthe cursor to column 9, line 1

       //(note: line 1 is the second row, since counting begins with 0):

      
  //Print the detected key

      
  lcd.print("KEY= ");

      
  lcd.print(key);

    }  

  }