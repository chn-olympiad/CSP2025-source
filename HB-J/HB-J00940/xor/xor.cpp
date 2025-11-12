#include <iostream>

int get_prefix(int* const all, const int& left, const int& right)
{
	return all[right] ^ (left - 1 >= 0 ? all[left - 1] : 0);
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	int n, limit;
	std::cin >> n >> limit;

	int* all = new int[n];
	for (int a = 0; a < n; a++)
	{
		std::cin >> all[a];

		if (a >= 1)
		{
			all[a] ^= all[a - 1];
		}
	}

	int count = 0;
	int r = 0;
	for (int l = 0; l < n; l++)
	{
		while (r < n && get_prefix(all, l, r) != limit)
		{
			r++;
		}

		if (r < n)
		{
			count++;
		}

		l = r;
	}

	std::cout << count << std::endl;

	return 0;
}
