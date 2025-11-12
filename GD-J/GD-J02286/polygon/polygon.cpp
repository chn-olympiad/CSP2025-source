#define Debug 0
#include <iostream>
#include <cstdint>

using namespace std;
// O(n)
bool Check(uint32_t *sticks, uint32_t sticksLength)
{
	uint32_t maxLength = 0, sum = 0;
	for (uint32_t index = 0; index < sticksLength; index++)
	{
		sum += sticks[index];
		if (sticks[index] > maxLength)
			maxLength = sticks[index];
	}
	if (sum > maxLength * 2)
		return true;
	return false;
}

int main()
{
	#if !Debug
		freopen("polygon.in", "r", stdin);
		freopen("polygon.out", "w", stdout);
	#endif
	uint32_t n, *sticks, input, sum = 0;
	cin >> n;
	sticks = new uint32_t[n];
	for (uint32_t inputIndex = 0; inputIndex < n; inputIndex++)
	{
		cin >> input;
		sticks[inputIndex] = input;
	}
	for (uint32_t checkStart = 0; checkStart <= n; checkStart++)
	{
		for (uint32_t checkEnd = checkStart; checkEnd <= n; checkEnd++)
		{
			sum += Check(sticks + checkStart, checkEnd-checkStart);
		}
	}
	cout << sum;
	#if !Debug
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
