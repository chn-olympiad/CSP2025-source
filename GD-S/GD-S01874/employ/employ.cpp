#include <bits/stdc++.h>
#define int long long
const int MAXN = 5e2 + 10, INF = 0x3f3f3f3f, mod = 998244353;
using namespace std;
int n, m, ans;
int a[MAXN];
char s[MAXN];
bitset<MAXN> ok;
void dg(int x, int y)
{
	if ( x > n )
	{
		if ( n - y >= m )
		{
			ans++;
			if ( ans > mod )
			{
				ans -= mod;
			}
		}
		return;
	}
	for ( int i = 1; i <= n; i++ )
	{
		if ( ok[i] )
		{
			continue;
		}
		ok[i] = 1;
		if ( y >= a[i] || s[x] == '0' )
		{
			dg(x + 1, y + 1);
		}
		else
		{
			dg(x + 1, y);
		}
		ok[i] = 0;
	}
}
signed main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%lld%lld%s", &n, &m, s + 1);
	for ( int i = 1; i <= n; i++ )
	{
		cin >> a[i];
	}
	dg(1, 0);
	printf("%lld", ans);
	return 0;
}
