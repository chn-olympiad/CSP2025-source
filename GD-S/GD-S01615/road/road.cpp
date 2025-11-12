#include <bits/stdc++.h>
using namespace std;
struct node
{
	int u, v, w;
}a[10005];
vector<int> g[10005];
bool vis[10005];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
bool bfs(int x, int y)
{
	memset(vis, false, sizeof(vis));
	queue<int> q;
	q.push(x);
	vis[x] = true;
	while (!q.empty())
	{
		int tx = q.front();
		q.pop();
		for (int i = 0; i < g[tx].size(); i++)
		{
			if (vis[g[tx][i]] == false)
			{
				if (g[tx][i] == y) return false;
				vis[g[tx][i]] = true;
				q.push(g[tx][i]);
			}
		}
	}
	return true;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i].u >> a[i].v >> a[i].w;
	}
	if (k == 0)
	{
		int ans = 0;
		sort(a + 1, a + m + 1, cmp);
		for (int i = 1; i <= m; i++)
		{
			if (bfs(a[i].u, a[i].v))
			{
				ans += a[i].w;
				g[a[i].u].push_back(a[i].v);
				g[a[i].v].push_back(a[i].u);
			}
		}
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	return 0;
}
