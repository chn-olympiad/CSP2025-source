#include <bits/stdc++.h>
#define int long long
const int MAXN = 1e5 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
using namespace std;
int T, n, ans, A;
int sum[MAXN];
int a[5][MAXN];
bool cmp(int x, int y)
{
	return x > y;
}
void dfs(int x, int num1, int num2, int num3, int maxn)
{
	if ( num1 > n / 2 || num2 > n / 2 || num3 > n / 2 || maxn + sum[n] - sum[x - 1] <= ans )
	{
		return;
	}
	if ( x > n )
	{
		ans = maxn;
		return;
	}
	int maxx = max(max(a[1][x], a[2][x]), a[3][x]);
	if ( maxx == a[1][x] )
	{
		dfs(x + 1, num1 + 1, num2, num3, maxn + a[1][x]);
		if ( a[2][x] > a[3][x] )
		{
			dfs(x + 1, num1, num2 + 1, num3, maxn + a[2][x]);
			dfs(x + 1, num1, num2, num3 + 1, maxn + a[3][x]);
			return;
		}
		dfs(x + 1, num1, num2, num3 + 1, maxn + a[3][x]);
		dfs(x + 1, num1, num2 + 1, num3, maxn + a[2][x]);
		return;
	}
	if ( maxx == a[2][x] )
	{
		dfs(x + 1, num1, num2 + 1, num3, maxn + a[2][x]);
		if ( a[1][x] > a[3][x] )
		{
			dfs(x + 1, num1 + 1, num2, num3, maxn + a[1][x]);
			dfs(x + 1, num1, num2, num3 + 1, maxn + a[3][x]);
			return;
		}
		dfs(x + 1, num1, num2, num3 + 1, maxn + a[3][x]);
		dfs(x + 1, num1 + 1, num2, num3, maxn + a[1][x]);
		return;
	}
	dfs(x + 1, num1, num2, num3 + 1, maxn + a[3][x]);
	if ( a[2][x] > a[1][x] )
	{
		dfs(x + 1, num1, num2 + 1, num3, maxn + a[2][x]);
		dfs(x + 1, num1 + 1, num2, num3, maxn + a[1][x]);
		return;
	}
	dfs(x + 1, num1 + 1, num2, num3, maxn + a[1][x]);
	dfs(x + 1, num1, num2 + 1, num3, maxn + a[2][x]);
}
void solve()
{
	ans = 0;
	A = 1;
	scanf("%lld", &n);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%lld%lld%lld", &a[1][i], &a[2][i], &a[3][i]);
		sum[i] = sum[i - 1] + max(max(a[1][i], a[2][i]), a[3][i]);
		if ( a[2][i] > 0 || a[3][i] > 0 )
		{
			A = 0;
		}
	}
	if ( A == 1 )
	{
		sort(a[1] + 1, a[1] + n + 1, cmp);
		for ( int i = 1; i <= n / 2; i++ )
		{
			ans += a[1][i];
		}
	}
	else
	{
		dfs(1, 0, 0, 0, 0);
	}
	printf("%lld\n", ans);
}
signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	for ( cin >> T; T--; )
	{
		solve();
	}
	return 0;
}
