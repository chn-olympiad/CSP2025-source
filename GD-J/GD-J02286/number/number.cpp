#define Debug 0
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
	#if !Debug
		freopen("number.in", "r", stdin);
		freopen("number.out", "w", stdout);
	#endif
	string s, *output;
	uint8_t currentNumber;
	uint32_t *NumberCount = new uint32_t[9];
	for (uint8_t initIndex = 0; initIndex < 9; initIndex++)
		NumberCount[initIndex] = 0;
	cin >> s;
	for (uint32_t stringIndex = 0; stringIndex < s.length(); stringIndex++)
	{
		currentNumber = s[stringIndex] - '0';
		if (currentNumber < 10)
			NumberCount[currentNumber]++;
	}
	#if Debug
	for (uint16_t outputIndex = 0; outputIndex <= 9; outputIndex++)
		cout << outputIndex << ':' << NumberCount[outputIndex] << ' ';
	#endif
	int8_t outputIndex = 9;
	while (outputIndex >= 0)
	{
		if (NumberCount[outputIndex])
			while (NumberCount[outputIndex])
			{
				cout << ((uint16_t)outputIndex);
				NumberCount[outputIndex]--; 
			}
		outputIndex--;
	}
	#if !Debug
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
