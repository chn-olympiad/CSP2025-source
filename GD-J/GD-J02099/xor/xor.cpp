#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e2 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, ans, last = -1;
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	if ( m == 0 )
	{
		for ( int i = 1, x; i <= n; i++ )
		{
			scanf("%lld", &x);
			if ( x == 0 )
			{
				ans++;
				last = -1;
			}
			else
			{
				if ( last == 1 )
				{
					ans++;
					last = -1;
				}
				else
				{
					last = 1;
				}
			}
		}
	}
	else
	{
		if ( m == 1 )
		{
			for ( int i = 1, x; i <= n; i++ )
			{
				scanf("%lld", &x);
				if ( x == 1 )
				{
					ans++;
				}
			}
		}
		else
		{
			for ( int i = 1, x; i <= n; i++ )
			{
				scanf("%lld", &x);
				if ( last == -1 )
				{
					last = x;
				}
				else
				{
					last ^= x;
				}
				if ( last == m )
				{
					ans++;
					last = -1;
				}
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
