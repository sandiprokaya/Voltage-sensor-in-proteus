// include the library code: 
#include <LiquidCrystal.h> //library for LCD 

// initialize the library with the numbers of the interface pins 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8); 

#include "EmonLib.h"   // Include Emon Library
EnergyMonitor emon1;   // Create an instance

void setup()
{
  emon1.voltage(A0,189, 1.7); // Voltage: input pin, calibration, phase_shift

  lcd.begin(20, 4); // set up the LCD's number of columns and rows:
  lcd.setCursor(0,0);
  lcd.print("  THE BRIGHT LIGHT    ");
  lcd.setCursor(0,1);
  lcd.print(" MEASURE AC VOLTAGE             ");
}

void loop()
{
  emon1.calcVI(20,2000); // Calculate all. No.of half wavelengths (crossings), time-out
  int Voltage   = emon1.Vrms;  //extract Vrms into Variable
  
  lcd.setCursor(0,3);
  lcd.print("   VOLTAGE = ");
  lcd.print(Voltage);
  lcd.print("V         ");
}
