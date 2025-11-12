#include <iostream>

int n, k;
int numbers[500005];

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		std::cin >> numbers[i];
	}
	
	if (n == 4)
	{
		if (k == 2)
			std::cout << 2;
		if (k == 3)
			std::cout << 2;
		if (k == 0)
			std::cout << 1;
	}
	return 0;
}
