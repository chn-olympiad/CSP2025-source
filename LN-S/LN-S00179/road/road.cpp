#include<bits/stdc++.h>
//#define int long long
#define rep(a,b,c) for(int a=b;a<=c;a++)
#define dep(a,b,c) for(int a=b;a>=c;a--)
#define pb push_back
using namespace std;

const int N = 2e4+10, M = 1e6 + 10;

int n, m, k, f[N], g[N][N], c[11], ans = 1e9, ok[20], d[N];
bool vis[N];
struct edge
{
	int u, v, w;
	bool operator< (const edge &a) const
	{
		return w < a.w;
	}
}e[M];

int find(int u)
{
	return (u == f[u]) ? u : (f[u] = find(f[u]));
}

signed main()
{
	freopen("road.in", "r", stdin);freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	memset(g, -1, sizeof g);
	cin >> n >> m >> k;
	rep(i, 1, n + k) f[i] = i;
	rep(i, 1, m)
	{
		cin >> e[i].u >> e[i].v >> e[i].w;
		int u = e[i].u, v = e[i].v, w = e[i].w;
		g[u][v] = g[v][u] = w;
	}
	rep(i, 1, k)
	{
		cin >> c[i];
		rep(j, 1, n) cin >> g[n + i][j];
	}
	rep(i, 1, n + k)
	{
		rep(j, 1, n + k) cout << g[i][j] << " ";
		cout << endl;
	}
	sort(e + 1, e + m + 1);
	if (k == 0)
	{
		rep(i, 1, m)
		{
			int u = e[i].u, v = e[i].v, w = e[i].w;
			int fu = find(u), fv = find(v);
			if (fu == fv) continue;
			f[fu] = fv;
			ans += w;
		}
		cout << ans << endl;
		return 0;
	}
	rep(p, 0, (1 << k) - 1)
	{
		memset(ok, 0, sizeof ok);
		memset(vis, 0, sizeof vis);
		int res = 0, ver = 1;
		rep(i, 1, k)
			if (p & (1 << (i - 1))) res += c[i], ok[i] = 1;
		while (1)
		{
			int dis = 1e9, v = -1;
			vis[ver] = 1;
			rep(i, 1, n + k)
			{
				if (vis[i]) continue;
				if (i > n && ok[i - n] == 0) continue;
				if (g[ver][i] < dis && g[ver][i] != -1) dis = g[ver][i], v = i;
			}
			if (v == -1) break;
			ver = v, res += dis;
		}
		if (ans > res) ans = res;
	}
	cout << ans << endl;
	return 0;
}
//Ren5Jie4Di4Ling5%
