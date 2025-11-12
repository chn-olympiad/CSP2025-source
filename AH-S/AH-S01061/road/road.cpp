#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, c, fa[20005], tot, sum, u, v, w, ans = 1e9, num;
struct Edge
{
	int from, to, w;
}edge[20005];
void add(int x, int y, int z)
{
	edge[++tot].to = y;
	edge[tot].from = x;
	edge[tot].w = z;
}
int find(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	return fa[x] = find(fa[x]);
}
bool cmp(Edge x, Edge y)
{
	return x.w < y.w;
}
signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		cin >> u >> v >> w;
		add(u, v, w);
	}
	sort(edge + 1, edge + tot + 1, cmp);
	int cnt = n, sum = 0;
	for (int j = 1; j <= tot; j++)
	{
		if (cnt == 1)
		{
			break;
		}
		int x = edge[j].from, y = edge[j].to;
		int rx = find(x), ry = find(y);
		if (rx == ry)
		{
			continue;
		}
		sum += edge[j].w;
		fa[rx] = ry;
		cnt--;
	}
	ans = min(ans, sum);
	for (int i = 1; i <= k; i++)
	{
		sum = 0;
		cin >> c;
		num += c;
		int cnt = n + i;
		for (int j = 1; j <= n + i; j++)
		{
			fa[j] = j;
		}
		for (int j = 1; j <= n; j++)
		{
			cin >> w;
			add(j, n + i, w);
		}
		sort(edge + 1, edge + tot + 1, cmp);
		for (int j = 1; j <= tot; j++)
		{
			if (cnt == 1)
			{
				break;
			}
			int x = edge[j].from, y = edge[j].to;
			int rx = find(x), ry = find(y);
			if (rx == ry)
			{
				continue;
			}
			sum += edge[j].w;
			fa[rx] = ry;
			cnt--;
		}
		ans = min(ans, sum + num);
	}
	printf("%lld", ans);
	return 0;
}
