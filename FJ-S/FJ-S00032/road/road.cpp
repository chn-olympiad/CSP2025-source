#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int N = 1e4 + 5;//////////
const int M = 1e6 + 5;//////////
const int MXG = 7e6 + 5;
int n, m, k, ans, cnte, c[15], a[15][N], fa[N], rk[N];
struct Node
{
	int to, w;
	bool tag;
};
struct edge
{
	int u, v, w;
};
vector<Node> G[MXG];
vector<edge> E;
void init(){for(int i = 1; i <= n; i++)fa[i] = i, rk[i] = 1;}
int find(int x){return x == fa[x] ? x : (fa[x] = find(fa[x]));}
void merge(int i, int j)
{
	int x = find(i), y = find(j);
	(rk[x] <= rk[y]) ? (fa[x] = y) : (fa[y] = x);
	if(rk[x] == rk[y])rk[y]++;
}
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
void kruscal()
{
	ans = 0;
	sort(E.begin(), E.end(), cmp);
	for(int i = 0; i < E.size(); i++)
	{
		edge e = E[i];
		int u = e.u, v = e.v, w = e.w;
		if(find(u) == find(v))continue;
		merge(u, v);
		ans += w;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	init();
	for(int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		G[u].push_back({v, w, 0});
		G[v].push_back({u, w, 0});
		E.push_back({u, v, w});
	}
	for(int i = 1; i <= k; i++)
	{
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++)scanf("%d", &a[i][j]);
		for(int j = 1; j < n; j++)
			for(int k = j + 1; k <= n; k++)
			{
				G[j].push_back({k, a[i][j] + a[i][k], 1});
				G[k].push_back({j, a[i][j] + a[i][k], 1});
				E.push_back({k, j, a[i][j] + a[i][k]});
			}
	}
	kruscal();
	printf("%d\n", ans);
	return 0;
}
