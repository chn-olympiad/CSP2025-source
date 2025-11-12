#define Debug 0
#include <iostream>
#include <cstdint>

using namespace std;

int main()
{
	#if !Debug
		freopen("xor.in", "r", stdin);
		freopen("xor.out", "w", stdout);
	#endif
	uint32_t n, k;
	cin >> n >> k;
	uint32_t *numbers = new uint32_t[n], input, result = 0, sum, x0, x1, *triggerPair0 = new uint32_t[n * n], end;
	for (uint32_t inputIndex = 0; inputIndex < n; inputIndex++)
	{
		cin >> input;
		numbers[inputIndex] = input;
	}
	if (n)
		for (x0 = 0; x0 <= n; x0++)
		{
			sum = numbers[x0];
				for (x1 = x0 + 1; x1 <= n; x1++)
				{
					if (sum == k)
					{
						x0 = x1 - 1;
						result++;
						break;
					}
					sum = sum ^ numbers[x1];
				}
		}
	cout << result;
	#if !Debug
		fclose(stdin);
		fclose(stdout);
	#endif
	return 0;
} 
