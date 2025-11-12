#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e2 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
int n, m, top;
pair<int, int> a[MAXN];
signed main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for ( int i = 1; i <= n * m; i++ )
	{
		scanf("%lld", &a[i].first);
		a[i].first *= -1;
		a[i].second = i;
	}
	sort(a + 1, a + n * m + 1);
	for ( int i = 1; i <= n; i++ )
	{
		if ( i & 1 )
		{
			for ( int j = 1; j <= m; j++ )
			{
				top++;
				if ( a[top].second == 1 )
				{
					printf("%lld %lld", i, j);
					return 0;
				}
			}
		}
		else
		{
			for ( int j = m; j >= 1; j-- )
			{
				top++;
				if ( a[top].second == 1 )
				{
					printf("%lld %lld", i, j);
					return 0;
				}
			}
		}
	}
	return 0;
}
