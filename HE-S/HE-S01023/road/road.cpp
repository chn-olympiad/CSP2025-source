#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 10, M = 6e6 + 10;
#define ll long long
int n, m, k, now_edge, head[N], c[N], val[11][N], fa[N], tot;
ll ans;
struct Node
{
	int u, v, w, nxt;
} edg[M];
void add(int u, int v, int w)
{
	edg[++now_edge].v = v;
	edg[now_edge].w = w;
	edg[now_edge].u = u;
	edg[now_edge].nxt = head[u];
	head[u] = now_edge;
}
bool cmp(Node a, Node b)
{
	return a.w < b.w;
}
int find_fa(int x)
{
	if (fa[x] == x)
		return x;
	return fa[x] = find_fa(fa[x]);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int i = 1; i <= k; i++)
	{
		int cur;
		cin >> c[i];
		for (int j = 1; j <= n; j++)
		{
			cin >> val[i][j];
			if (!val[i][j])
				cur = j;
		}
		for (int j = 1; j <= n; j++)
			if (j != cur)
				add(cur, j, val[i][j]);
	}
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	sort(edg + 1, edg + 1 + now_edge, cmp);
	for (int i = 1; i <= now_edge; i++)
	{
		int x = find_fa(edg[i].u), y = find_fa(edg[i].v);
		if (x != y)
			fa[x] = y, tot++, ans += edg[i].w;
		if (tot == n - 1)
		{
			cout << ans;
			return 0;	
		}
	}
}
/*
4 6 1
1 2 2
1 3 4
1 4 2
2 4 3
3 4 7
4 4 1
0 999 999 0 1
*/
