#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e4, M = 2e6;
int n, m, k, f[N], t[15];
unsigned long long ans, h;
bool b[15], d[N];
struct edge
{
	int u, v, w;
} x[M];
bool cmp(edge a, edge b)
{
	return a.w < b.w;
}
int find(int x)
{
	if (x == f[x]) return x;
	return f[x] = find(f[x]);
}
bool merge(int x, int y)
{
	x = find(x), y = find(y);
	if (x == y) return 0;
	else
	{
		f[x] = y;
		return 1;
	}
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	h = 1llu * n * (n + 1) / 2;
	for (int i = 1, u, v, w; i <= m; i++)
	{
		scanf("%d%d%d", &u, &v, &w);
		x[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
	{
		scanf("%d", &t[i]);
		for (int j = 1, p; j <= n; j++)
		{
			scanf("%d", &p);
			x[++m] = {j, i + n, p + t[i]};
		}
	}
	for (int i = 1; i <= n + k; i++) f[i] = i;
	sort(x + 1, x + 1 + m, cmp);
	for (int i = 1; i <= m; i++)
	{
		int u = x[i].u, v = x[i].v, w = x[i].w;
		if (merge(u, v))
		{
			if (u > n && b[u - n]) w -= t[u - n];
			else if (u > n) b[u - n] = 1;
			else if (!d[u]) h -= u, d[u] = 1;
			if (v > n && b[v - n]) w -= t[v - n];
			else if (v > n) b[v - n] = 1;
			else if (!d[v]) h -= v, d[v] = 1;
			ans += w;
		}
		if (h <= 0) break;
	}
	printf("%llu", ans);
	return 0;
}
