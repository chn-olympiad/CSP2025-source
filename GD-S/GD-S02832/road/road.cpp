#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 30;
struct node{int x, y, w;};
bool cmp(node n1, node n2){return n1.w < n2.w;}
vector<pair<int, int> > G[N];
vector<node> edge;
int fa[N];
int findfa(int x){return (fa[x] == x ? x : fa[x] = findfa(fa[x]));}
int solve()
{
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		G[u].push_back({v, w}); G[v].push_back({u, w});
		if (u > v) swap(u, v);
		edge.push_back({u, v, w});
	}
	
	for (int i = 1; i <= k; i++)
	{
		int c, w; scanf("%d", &c);
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &w); 
			G[n + i].push_back({j, w});
			G[j].push_back({n + i, w});
			edge.push_back({min(j, n + i), max(j, n + i), w});
		}
	}
	
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	sort(edge.begin(), edge.end(), cmp);
	int ans = 0, cnt = 0;
	//cout << edge.size() << endl;
	//for (int i = 0; i < edge.size(); i++) cout << edge[i].x <<' '<< edge[i].y<<' ' << edge[i].w  <<'\n';
	for (int i = 0; i < edge.size(); i++)
	{
		//cout << 666 << endl;
		int u = edge[i].x, v = edge[i].y, l = edge[i].w;
		//printf("%d %d %d %d %d %d\n", i, u, v, l, findfa(u), findfa(v));
		if (findfa(u) != findfa(v))
		{
			fa[findfa(u)] = findfa(v);
			cnt++;
			ans += l;
		}
		if (cnt == (n + k - 1)){break;} 
	}
	printf("%d", ans);
	return 0;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}


