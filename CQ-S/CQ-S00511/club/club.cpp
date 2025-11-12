#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

namespace wxr
{

const int maxn = 1e5 + 10;

long long a[maxn][4];

int c[4]; long long s[4];

std::vector<long long> vec[4];

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld %lld %lld", &a[i][1], &a[i][2], &a[i][3]);
		
		for (int j = 1; j <= 3; j++) c[j] = 0, s[j] = 0, vec[j].clear();
		
		for (int i = 1; i <= n; i++)
		{
			int max = 0;
			for (int j = 1; j <= 3; j++)
			{
				if (max == 0 || a[i][j] > a[i][max]) max = j;
			}
			long long max2 = 0;
			for (int j = 1; j <= 3; j++) if (max != j) max2 = std::max(max2, a[i][j]); 
			vec[max].push_back(a[i][max] - max2);
			c[max]++, s[max] += a[i][max];
		}
		
		long long ans = s[1] + s[2] + s[3];
		for (int j = 1; j <= 3; j++)
		{
			if (c[j] > n / 2)
			{
				std::sort(vec[j].begin(), vec[j].end());
				for (int i = 0; i < c[j] - n / 2; i++)
				{
					ans -= vec[j][i];
				}
				break;
			}
		}
		
		printf("%lld\n", ans);
	}
	return 0;
}



}

int main()
{
	wxr::main();
	return 0;
}

