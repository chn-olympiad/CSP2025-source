#define Debug 0
#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

int main()
{
	#if !Debug
		freopen("seat.in", "r", stdin);
		freopen("seat.out", "w", stdout);
	#endif
	uint32_t n, m, xPos, yPos;
	cin >> n >> m;
	uint64_t seatSize = n * m, seatIndex = 0;
	uint16_t studentResult, rResult;
	cin >> rResult;
	seatSize--;
	while (seatSize)
	{
		cin >> studentResult;
		if (studentResult > rResult)
			seatIndex++;
		seatSize--;
	}
	yPos = seatIndex % n;
	xPos = seatIndex / n;
	if (xPos % 2 == 1)
		yPos = n - 1 - yPos;
	cout << (xPos + 1) << ' ' << (yPos + 1);
	#if !Debug
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
