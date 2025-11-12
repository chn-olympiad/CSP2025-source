#include <bits/stdc++.h>
#define int long long
const int MAXN = 1e4 + 10, INF = 0x3f3f3f3f, mod = 1e9 + 7;
using namespace std;
int n, m, k, top;
bitset<MAXN> ok;
bool city[15][MAXN];
int head[MAXN];
int a[15][MAXN];
const int MAXM = 1e6 + 10;
struct Edge
{
	int to, next, num;
} e[MAXM << 1];
void join(int x, int y, int z)
{
	e[++top] = (Edge){y, head[x], z};
	head[x] = top;
}
int Prim()
{
	int op = 1, now = 1, ret = 0;
	while ( op < n )
	{
		int minn = 0x7f7f7f7f, qwq = 0, zx = 0;
		ok[now] = 1;
		for ( int i = head[now]; i; i = e[i].next )
		{
			if ( minn > e[i].num && !ok[e[i].to] )
			{
				qwq = e[i].to;
				minn = e[i].num;
			}
		}
		for ( int i = 1; i <= k; i++ )
		{
			for ( int j = 1; j <= n; j++ )
			{
				if ( j == now )
				{
					continue;
				}
if ( !city[i][now] * a[i][now] + !city[i][j] * a[i][j] + !city[i][0] * a[i][0] <= minn && !ok[j] )
				{
					zx = i;
					qwq = j;
minn = !city[i][now] * a[i][now] + !city[i][j] * a[i][j] + !city[i][0] * a[i][0];
				}
			}
		}
		now = qwq;
		ret += minn;
		op++;
		if ( zx )
		{
			city[zx][now] = city[zx][qwq] = city[zx][0] = 1;
		}
	}
	return ret;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &k);
	for ( int i = 1, x, y, z; i <= m; i++ )
	{
		scanf("%lld%lld%lld", &x, &y, &z);
		join(x, y, z);
		join(y, x, z);
	}
	for ( int i = 1; i <= k; i++ )
	{
		for ( int j = 0; j <= n; j++ )
		{
			scanf("%lld", &a[i][j]);
		}
	}
	printf("%lld", Prim());
	return 0;
}
