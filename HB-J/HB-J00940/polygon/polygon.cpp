#include <iostream>

const int mod = 998'244'353;

int search(int* const all, const int& size, const int& depth, const int& selected, const int& max_count, const int& total)
{
	static int count = 0;

	if (depth >= size)
	{
		if (selected >= 3 && total > max_count * 2)
		{
			count = (count + 1) % mod;
		}

		return count;
	}

	search(all, size, depth + 1, selected + 1, all[depth] > max_count ? all[depth] : max_count, total + all[depth]);
	search(all, size, depth + 1, selected, max_count, total);

	return count;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);

	int n;
	std::cin >> n;

	int* all = new int[n];
	for (int a = 0; a < n; a++)
	{
		std::cin >> all[a];
	}

	std::cout << search(all, n, 0, 0, 0, 0) << std::endl;

	return 0;
}
