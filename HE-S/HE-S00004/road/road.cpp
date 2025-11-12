#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 1, M = 1e6 + 1;
int n, m, k;
struct edge
{
	int u, v, w;
	bool operator < (edge y) const
	{
		return w < y.w;
	}
}e[M];
int f[N];
int Find(int u)
{
	return u == f[u] ? u : f[u] = Find(f[u]);
}
void Marge(int u, int v)
{
	f[Find(u)] = Find(v);
}
long long Kruskal()
{
	sort(e + 1, e + m + 1);
	iota(f + 1, f + n + 1, 1);
	long long MST = 0, cnt = 0;
	for (int i = 1; i <= n && cnt < n - 1; i++)
	{
		int u = e[i].u, v = e[i].v, w = e[i].w;
		if (Find(u) != Find(v))
		{
			Marge(u, v);
			cnt++;
			MST += w;
		}
	}
	return MST;
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1; m--; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	cout << Kruskal();
	return 0;
}
