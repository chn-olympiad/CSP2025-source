#include <bits/stdc++.h>
using namespace std;
constexpr int M = 1e6+5, N = 1e4+5;
struct Edge {
	int u, v, w;
	
	inline bool operator < (const Edge& eg) const
	{
		return this->w < eg.w;
	}
} edge[M + N * 10];
int fa[N + 10], num[N + 10], a[12][N], cst[12], ind[12], ct[12];
inline int getr(const int& x)
{
	return (fa[x] == x ? x : fa[x] = getr(fa[x]));
}
inline void merge(const int& x, const int& y)
{
	int lx = getr(x), ly = getr(y);
	if (num[lx] < num[ly])
		fa[lx] = ly, num[ly] += num[lx];
	else fa[ly] = lx, num[lx] += num[ly];
}
int n, m, k;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++)
	{
		cin >> edge[i].u >> edge[i].v >> edge[i].w;
//		if (edge[i].w < 1e7)
//			++ ccc;
			
	}
//	cout << ccc << '\n';
	for (int i = 1; i <= k; i ++)
	{
		cin >> cst[i];
		for (int j = 1; j <= n; j ++)
		{
			cin >> a[i][j];
			edge[++m] = {n + i, j, a[i][j]};
		}
	}
	sort(edge + 1, edge + m + 1);
	int sn = n + k;
//	int sn = n;
	for (int i = 1; i <= sn; i ++)
		fa[i] = i, num[i] = 1;
	long long ans = 0;
	for (int i = 1, cs = sn - 1; i <= m && cs > 0; i ++)
		if (getr(edge[i].u) != getr(edge[i].v))
		{
			-- cs;
			merge(edge[i].u, edge[i].v);
//			if (edge[i].w == 0)
//				cout << 1 << '\n';
			if (edge[i].u > n)
				++ ind[edge[i].u - n], ct[edge[i].u - n] = edge[i].w;
			ans += edge[i].w;
		}
	cout << ans << '\n';
	for (int i = 1; i <= k; i ++)
		if (ind[i] > 1)
			ans += cst[i];
		else ans -= ct[i];
	cout << ans << '\n';
	return 0;
}
