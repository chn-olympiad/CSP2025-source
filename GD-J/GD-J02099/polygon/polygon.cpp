#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e3 + 10, INF = 0x3f3f3f3f, mod = 998244353;
int n, one = 1;
int a[MAXN];
void dg(int x, int num, int sum, int maxn)
{
	if ( x == n + 1 )
	{
		if ( num >= 3 && sum > maxn * 2 )
		{
			one++;
			if ( one >= mod )
			{
				one -= mod;
			}
		}
		return;
	}
	dg(x + 1, num, sum, maxn);
	dg(x + 1, num + 1, sum + a[x], max(maxn, a[x]));
}
signed main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%lld", &n);
	for ( int i = 1; i <= n; i++ )
	{
		scanf("%lld", &a[i]);
		if ( a[i] != 1 )
		{
			one = 0;
		}
	}
	if ( one )
	{
		printf("%lld", ((1 << n) - n * (n - 1) / 2 - n - 1 + mod) % mod);
		return 0;
	}
	one = 0;
	dg(1, 0, 0, 0);
	printf("%lld", one);
	return 0;
}
