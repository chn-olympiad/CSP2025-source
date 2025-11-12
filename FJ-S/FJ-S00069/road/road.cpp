#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN = 10005;
const int MAXM = 1000005;
int n, m, k;
ll ans, cnt;
int c[15], fa[MAXN];
int b[15][MAXN], g[MAXN][MAXN];
bool vis[15];
struct Side{
	int u, v, w, id;
}a[4 * MAXM];
bool cmp (Side x, Side y)
{
	return x.w < y.w;
}
int find(int x)
{
	return fa[x] == x ? x : find(fa[x]);
}
void _swap(Side x, Side y)
{
	swap(x.u, y.u); swap(x.v, y.v);
	swap(x.w, y.w); swap(x.id, y.id);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	memset(g, 0x3f, sizeof(g));
	for (int i = 1; i <= m; i ++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
		g[a[i].u][a[i].v] = a[i].w;
	}
	for (int i = 1; i <= n; i ++) fa[i] = i;
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
			cin >> b[i][j];
	}
	sort(a + 1, a + m + 1, cmp);
	for (int i = 1; i <= m; i ++)
	{	
		int u = find(a[i].u), v = find(a[i].v);
		if (u != v)
		{
			fa[u] = v;
			ans += a[i].w;
		}
	}	
	if (k == 0)
	{
		cout << ans << endl;
		return 0;
	}
	ll t = ans;
	for (int j = 1; j <= k; j ++)
	{
		for (int i = 1; i <= n; i ++) fa[i] = i;
		cnt = 0; ans = 0;
		for (int x = 1; x <= n; x ++)
			for (int y = x + 1; y <= n; y ++)
			{
				int w = min(g[x][y], b[j][x] + b[j][y]);
				a[++cnt] = {x, y, w};	
			}
		sort(a + 1, a + cnt + 1, cmp);
		for (int i = 1; i <= cnt; i ++)
		{	
			int u = find(a[i].u), v = find(a[i].v);
			if (u != v)
			{
				fa[u] = v;
				ans += a[i].w;
			}
		}
		if (t - ans > c[j])	vis[j] = true;
	}
	for (int i = 1; i <= k; i ++)
		if (vis[i])
			t += c[i];
	cout << t << endl;	
	return 0;
}

