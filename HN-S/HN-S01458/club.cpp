#include <algorithm>
#include <cstdio>
#include <array>
#include <cstring>

namespace Fujiwara
{
using std::max;
using std::sort;
using std::array;
using std::greater;

using a3 = array<int, 3>;
using p3 = array<std::pair<int, int>, 3>;
const int N = 1e5 + 5;

a3 a[N];
p3 p[N];
int n, t;
int dp[405][405][405];
static int dfs(int i, int x1, int x2)
{
	int &f = dp[i][x1][x2];

	if (f != -1)
		return f;
	f = 0;
	if (i > n)
		return f;

	if (i - x1 - x2 <= n / 2)
		f = max(f, dfs(i + 1, x1, x2) + a[i][2]);
	if (x1 + 1 <= n / 2)
		f = max(f, dfs(i + 1, x1 + 1, x2) + a[i][0]);
	if (x2 + 1 <= n / 2)
		f = max(f, dfs(i + 1, x1, x2 + 1) + a[i][1]);
	return f;
}
static bool cmp(a3 x, a3 y)
{
	return x[0] - x[1] > y[0] - y[1];
}
static void solve()
{
	scanf("%d", &n);

	bool f = 1;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j <= 2; ++j)
			scanf("%d", &a[i][j]);
		f &= (!a[i][2]);
	}
	if (n <= 400)
	{
		memset(dp, 0xff, sizeof(dp));
		printf("%d\n", dfs(1, 0, 0));
	}
	else if (f)
	{
		int res = 0;
		sort(a + 1, a + n + 1, cmp);
		for (int i = 1; i <= n / 2; ++i)
			res += a[i][0];
		for (int i = n / 2 + 1; i <= n; ++i)
			res += max(a[i][1], a[i][2]);
		printf("fuck! %d\n", res);
	}
	else
	{
		int res = 0;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= 2; ++j)
				p[i][j] = {a[i][j], j};
			sort(p[i].begin(), p[i].end(), greater<std::pair<int, int>>());
		}
		a3 c;
		c[0] = c[1] = c[2] = 0;
		sort(p + 1, p + n + 1, greater<p3>());
		for (int i = 1; i <= n; ++i)
		{
			if (c[0] == n / 2 || c[1] == n / 2 || c[2] == n / 2)
				res += p[i][1].first;
			else
			{
				res += p[i][0].first;
				c[p[i][0].second]++;
			}
		}
		printf("%d\n", res);
	}
}
static int Azusa()
{
	scanf("%d", &t);

	while (t--)
		solve();
	return 0;
}
}
int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return Fujiwara::Azusa();
}