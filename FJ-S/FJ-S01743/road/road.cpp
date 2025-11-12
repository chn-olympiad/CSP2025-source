#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e16;
const int N = 1e4+100, M = 1e6+5;
struct Edge
{
	int v, w, nxt;
};
Edge e[M*3];
int head[N];
int cntpos = 0;
void add_edge(int u, int v, int w)
{
	e[++cntpos] = Edge{v, w, head[u]};
	head[u] = cntpos;
}
int n, m, k;
int dis[N];
bool vis[N];
int c[N], a[15][N];
int Prim(int cnt)
{
	int s = 1;
	for (int i=1;i<=cnt;i++)
	{
		dis[i] = inf;
		vis[i] = 0;
	}
	dis[s] = 0;
	int ans = 0;
	for (int i=1;i<=cnt;i++)
	{
		int minn = inf, pos = 0;
		for (int j=1;j<=cnt;j++)
		{
			if (minn > dis[j] && vis[j] == 0)
			{
				minn = dis[j], pos = j;
			} 
		}
		if (pos != 0)
		{
			vis[pos] = 1;
			ans += dis[pos];
			for (int j=head[pos];j!=0;j=e[j].nxt)
			{
				int v = e[j].v, w = e[j].w;
				if (vis[v] == 0)
					dis[v] = min(dis[v], w);
			}
		}
	}
	return ans;
}
void add(int u, int v, int w)
{
	add_edge(u, v, w);
	add_edge(v, u, w);
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i=1;i<=m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	if (k == 0)
	{
		cout << Prim(n);
		return 0;
	}
	for (int i=1;i<=k;i++)
	{
		cin >> c[i];
		for (int j=1;j<=n;j++)
			cin >> a[i][j];
	} 
	int ans = Prim(n);
	int sum = 0;
	for (int i=1;i<=k;i++)
	{
		sum += c[i];
		for (int j=1;j<=n;j++)
			add(n+i, j, a[i][j]);
	}
	ans = min(ans, Prim(n+k));
	cout << ans;
	return 0;
}


//4 4 2
//1 4 6
//2 3 7
//4 2 5
//4 3 4
//1 1 8 2 4
//100 1 3 2 4
