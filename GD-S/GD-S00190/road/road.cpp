#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e4 + 20 , M = 1e6 + 5;
unsigned short n , k;
unsigned m;
struct edge
{
	unsigned short u , v;
	int w;
	bool operator < (edge E) const
	{return w < E.w;}
} a[M];
edge b[M];
vector <edge> g;
unsigned short f[N];
int C[N];
unsigned short find (unsigned short u)
{
	if (f[u] == u) return u;
	return f[u] = find (f[u]);
}
signed main ()
{
	freopen ("road.in" , "r" , stdin);
	freopen ("road.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	cin >> n >> m >> k;
	for (unsigned  i = 1;i <= m;i ++) cin >> a[i].u >> a[i].v >> a[i].w;
	sort (a + 1 , a + m + 1);
	for (unsigned short i = 1;i <= n;i ++) f[i] = i;
	int ans = 0;
	for (unsigned i = 1;i <= m;i ++)
	{
		int u = find (a[i].u) , v = find (a[i].v);
		if (u != v) f[u] = v , g.push_back (a[i]) , ans += a[i].w;
	}
	unsigned cc = 0;
	for (int i = 0;i < k;i ++)
	{
		cin >> C[i];
		for (int j = 1;j <= n;j ++)
		{
			int x;
			cin >> x;
			b[++ cc] = {i , j , x};
		}
	}
	sort (b + 1 , b + cc + 1);
	unsigned short A = 1 << k;
	for (unsigned short S = 1;S < A;++ S)
	{
		for (unsigned short i = 1;i <= n + k;++ i) f[i] = i;
		int sum = 0;
		unsigned short p = 1 , cnt = n - 1;
		for (unsigned short i = 0;i < k;++ i) if (S >> i & 1) sum += C[i] , cnt ++;
		for (auto it : g)
		{
			while (p <= cc && b[p].w <= it.w)
			{
				if (S >> b[p].u & 1)
				{
					int u = find (b[p].u + n + 1) , v = find (b[p].v);
					if (u != v) f[u] = v , sum += b[p].w , -- cnt;
				}
				++ p;
			}
			unsigned short u = find (it.u) , v = find (it.v);
			if (u != v) f[u] = v , sum += it.w , -- cnt;
			if (!cnt || sum >= ans) break;
		}
		ans = min (ans , sum);
	}
	cout << ans << '\n';
	return 0;
}
