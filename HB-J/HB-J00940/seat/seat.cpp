#include <iostream>
#include <algorithm>

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	int* all = new int[n * m];
	for (int a = 0; a < n * m; a++)
	{
		std::cin >> all[a];
	}
	int target = all[0];

	std::sort(all, all + n * m);

	int unique_count = std::unique(all, all + n * m) - all;

	target = std::lower_bound(all, all + unique_count, target) - all;
	target = n * m - target - 1;
	
	int column, line;
	column = target / n;
	line = target % n;
	
	if (column % 2 == 1)
	{
		line = n - line - 1;
	}

	std::cout << column + 1 << ' ' << line + 1 << std::endl;

	return 0;
}
