#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e4 + 5, M = 2e6 + 5;
int n, m, k, cnt, tmp, tot, head[N], fa[N], c[15], a[N][15];
bool vis[N];
ll ans = 1e18;
struct Edge
{
	int u, v, w;
}edge[M << 1];
void add(int u, int v, int w)
{
	edge[++cnt] = {u, v, w};
}
int find(int u)
{
	return fa[u] == u ? u : fa[u] = find(fa[u]);
}
void merge(int u, int v)
{
	fa[find(u)] = find(v);
}
bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= n;i++)
		fa[i] = i;
	for(int i = 1;i <= m;i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	for(int i = 1;i <= k;i++)
	{
		cin >> c[i];
		for(int j = 1;j <= n;j++)
			cin >> a[i][j];
	}
	tmp = cnt;	
	for(int s = 0;s < (1 << k);s++)
	{
		ll res = 0, o = 0;
		cnt = tmp;
		tot = 0;
		for(int i = 1;i <= n;i++)
			fa[i] = i;
		for(int i = 1;i <= k;i++)
		{
			if(s & (1 << i))
			{
				o++;
				for(int j = 1;j <= n;j++)
					add(i + n, j, a[i][j]);
				res += c[i];
			}
		}
		sort(edge + 1, edge + cnt + 1, cmp);
		for(int i = 1;i <= cnt;i++)
		{
			int u = edge[i].u, v = edge[i].v, w = edge[i].w;
			if(find(u) == find(v)) continue;
			merge(u, v);
			res += w;
			tot++;
			if(tot == n + o - 1) break;
		}
		ans = min(ans, res);
	}
	cout << ans << "\n";
	return 0;
}
