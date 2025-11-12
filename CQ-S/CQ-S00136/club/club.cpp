#include <stdio.h>
#include <vector>
#include <algorithm>
int T, n;
std::vector<int> vec[3];
int min(int x, int y) { return x < y ? x : y; }
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	scanf("%d", &T);
	while (~--T)
	{
		scanf("%d", &n);
		int ans = 0;
		for (int i = 1, a, b, c; i <= n; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (a >= b && a >= c)
			{
				ans += a;
				vec[0].push_back(min(a - b, a - c));
			}
			else if (b >= a && b >= c)
			{
				ans += b;
				vec[1].push_back(min(b - a, b - c));
			}
			else
			{
				ans += c;
				vec[2].push_back(min(c - a, c - b));
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			std::sort(vec[i].begin(), vec[i].end(), [](int x, int y) { return x > y; });
			while (vec[i].size() > (n >> 1))
			{
				ans -= vec[i].back();
				vec[i].pop_back();
			}
			vec[i].clear();
		}
		printf("%d\n", ans);
	}
	return 0;
}