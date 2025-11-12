#include <bits/stdc++.h>
using namespace std;
struct Node
{
	long long u, v, w;
} node[2000005];
long long n, m, k, fa[10005], ans, c[15], a[15][10005], p;
bool flag = 1;
long long find(int x)
{
	return fa[x] == x ? x : find(fa[x]);
}
bool cmp(Node x, Node y)
{
	if (x.w == y.w)
	{
		if (x.u == y.u)
			return x.v < y.v;
		return x.u < y.u;
	}
	return x.w < y.w;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i ++)
		fa[i] = i;
	for (int i = 1; i <= m; i ++)
	{
		long long uu, vv, ww;
		cin >> uu >> vv >> ww;
		node[i] = {uu, vv, ww};
	}
	for (int i = 1; i <= k; i ++)
	{
		cin >> c[i];
		for (int j = 1; j <= n; j ++)
			cin >> a[i][j];
		if (c[i] != 0)
			flag = 0;
	}
	sort(node + 1, node + m + 1, cmp);
	for (int i = 1; i <= m; i ++)
	{
		int uu = find(node[i].u), vv = find(node[i].v);
		if (uu != vv)
		{
			ans += node[i].w;
			fa[vv] = uu;
		}
	}
	if (k == 0)
	{
		cout << ans;
		return 0;
	}
	if (flag)
	{
		ans = 0;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= k; j ++)
				node[++ p] = {n + j, i, a[j][i]};
		sort(node + 1, node + p + 1, cmp);
		for (int i = 1; i <= n + k; i ++)
			fa[i] = i;
		for (int i = 1; i <= p; i ++)
		{
			int uu = find(node[i].u), vv = find(node[i].v);
			if (uu != vv)
			{
				ans += node[i].w;
				fa[vv] = uu;
			}
		}
		cout << ans;
		return 0;
	}
	for (int i = 1; i <= (1 << k) - 1; i ++)
	{
		long long anss = 0, p = m;
		for (int j = 0; j < k; j ++)
			if (i & (1 << j))
			{
				anss += c[j + 1];
				for (int l = 1; l <= n; l ++)
					node[++ p] = {n + j + 1, l, a[j + 1][l]};
			}
		for (int i = 1; i <= n + k; i ++)
			fa[i] = i;
		sort(node + 1, node + p + 1, cmp);
		for (int i = 1; i <= p; i ++)
		{
			int uu = find(node[i].u), vv = find(node[i].v);
			if (uu != vv)
			{
				anss += node[i].w;
				fa[vv] = uu;
			}
			if (anss > ans)
				break;
		}
		ans = min(ans, anss);
	}
	cout << ans;
	return 0;
}
