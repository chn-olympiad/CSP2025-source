#include <bits/stdc++.h>
using namespace std;
const int M = 5e6 + 1;
struct edge
{
	int u, v, w;
} jiedian[M];
int fa[M];
int Find(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
}
void Union(int x, int y)
{
	fa[Find(x)] = fa[Find(y)];
}
bool isSameSet(int x, int y)
{
	return Find(x) == Find(y);
}
int main()
{
	long long ans = 0;
	int cnt = 0;
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= n + k; ++i)
		fa[i] = i;
	for (int i = 1, u, v, w; i <= m; ++i)
		scanf("%d%d%d", &u, &v, &w), jiedian[cnt++] = {u, v, w};
	for (int i = 1, c; i <= k; ++i)
	{
		scanf("%d", &c);
		for (int j = 1, a; j <= n; ++j)
			scanf("%d", &a), jiedian[cnt++] = {i + n, j, a};
	}
	sort(jiedian, jiedian + cnt, [](edge a, edge b) {
		return a.w < b.w;
	});
	for (int i = 0, tmp = 0; i < cnt; ++i)
	{
		if (!isSameSet(jiedian[i].u, jiedian[i].v))
			Union(jiedian[i].u, jiedian[i].v), ans += jiedian[i].w,
			++tmp;
		if (tmp == n + k - 1)
		{
			printf("%lld", ans);
			return 0;
		}
	}
	return 0;
}
