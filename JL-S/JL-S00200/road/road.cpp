#include <iostream>
#include <algorithm>
#define int long long

using namespace std;

const int N = 20010, M = 1500010;

int n, m, k, nn, mm;
int p[N], d[N], w[N];
int c[11], a[11][N];
struct Edge
{
	int u, v, w;
	bool operator< (const Edge &t)const
	{
		return w < t.w;
	}
} e[M], t[M];

int find(int x)
{
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void solve1()
{
	int cnt = 0, res = 0;
	sort(e + 1, e + mm + 1);
	for (int i = 1; i <= nn; i ++ ) p[i] = i;
	for (int i = 1; i <= mm; i ++ )
	{
		int r1 = find(e[i].u), r2 = find(e[i].v);
		if (r1 != r2) p[r2] = r1, res += e[i].w, t[ ++ cnt] = e[i];
		if (cnt == nn - 1) break;
	}
	printf("%lld\n", res);
}

void solve2()
{
	int cnt = 0, res = 0;
	sort(e + 1, e + mm + 1);
	for (int i = 1; i <= nn; i ++ ) p[i] = i;
	for (int i = 1; i <= mm; i ++ )
	{
		int r1 = find(e[i].u), r2 = find(e[i].v);
		if (r1 != r2) p[r2] = r1, res += e[i].w, t[ ++ cnt] = e[i];
		if (cnt == nn - 1) break;
	}
	for (int i = 1; i <= k; i ++ )
	{
		int tmp = 0;
		for (int j = 1; j <= n; j ++ )
			if (!a[i][j]) { tmp = j; break; }
		for (int j = 1; j <= cnt; j ++ )
		{
			if (t[j].u == tmp)
				res = min(res, res - t[j].w + a[i][t[j].v]);
			if (t[j].v == tmp)
				res = min(res, res - t[j].w + a[i][t[j].u]);
		}
	}
	printf("%lld\n", res);
}

signed main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int x, y, z, s = 0;
	scanf("%lld%lld%lld", &n, &m, &k);
	mm = 0, nn = n + k + k;
	for (int i = 1; i <= m; i ++ )
	{
		scanf("%lld%lld%lld", &x, &y, &z);
		e[ ++ mm] = {x, y, z};
	}
	for (int i = 1; i <= k; i ++ )
	{
		scanf("%lld", &c[i]), s += c[i];
		e[ ++ mm] = {n + i, n + k + i, c[i]};
		for (int j = 1; j <= n; j ++ )
		{
			scanf("%lld", &a[i][j]);
			e[ ++ mm] = {n + k + i, j, a[i][j]};
		}
	}

	if (!k) solve1();
	else if (!s) solve2();
	else solve1();

	// for (int i = 1; i <= cnt; i ++ )
	// {
	// 	d[t[i].u] ++ , d[t[i].v] ++ ;
	// 	if (t[i].u >= n + k && t[i].u <= n + k + k) w[t[i].u] += t[i].w;
	// 	if (t[i].v >= n + k && t[i].v <= n + k + k) w[t[i].v] += t[i].w;
	// 	printf("%lld %lld %lld\n", t[i].u, t[i].v, t[i].w);
	// }

	// for (int i = n + k + 1; i <= n + k + k; i ++ )
	// {
	// 	if (d[i] == 1) res -= w[i];
	// }

	// printf("%lld\n", res);
	return 0;
}