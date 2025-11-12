#include <bits/stdc++.h>
//#define int long long
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> piii;
const int N = 1e4 + 10, M = 1e6 + 10;

int c[15], w[15][N], mint[15];
bool vis[15];
struct edge
{
	int u, v, w;
} e[M + 10 * N];
bool cmp(edge x, edge y) {return x.w < y.w;}
int f[N + 20];
int find(int x)
{
	if (f[x] == x) return x;
	return f[x] = find (f[x]);
}
//struct node
//{
//	int w, id, u, v;
//	friend bool operator > (node x, node y)
//	{
//		return x.w > y.w;
//	}
//};
//priority_queue <node, vector <node>, greater <node> > q;

signed main()
{
	freopen ("road.in", "r", stdin);
	freopen ("road.out", "w", stdout);
	int n, m, k;
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
	{
		int x, y, w;
		scanf ("%d %d %d", &x, &y, &w);
		e[i] = {x, y, w};
	}
//	sort (e + 1, e + m + 1, cmp);
	ll ans = 9e18;
	for (int i = 1; i <= k; ++i)
	{
		scanf ("%d", c + i);
		for (int j = 1; j <= n; ++j)
		{
			scanf ("%d", &w[i][j]);
			if (!mint[i] || w[i][j] < w[i][mint[i]]) mint[i] = j;
		}
		for (int j = 1; j <= n; ++j)
			e[++m] = {n + i, j, w[i][j]};
//		for (int j = 1; j < n; j++)
//			q.push ((node){w[i][j] + w[i][j + 1], i, j, j + 1});
	}
	sort (e + 1, e + m + 1, cmp);
	for (int i = 0; i < (1 << k); ++i)
	{
		ll res = 0;
		for (int j = 1; j <= n + k; ++j) f[j] = j;
		int cnt = 0;
		for (int j = 1; j <= k; ++j)
			if ((i >> (j - 1)) & 1) res += c[j], cnt--;
		for (int j = 1; j <= m; ++j)
		{
			if (e[j].u > n && !((i >> (e[j].u - n - 1)) & 1)) continue;
			int u = find (e[j].u), v = find (e[j].v), w = e[j].w;
			if (u == v) continue;
			f[u] = v, res += w;
			if (cnt == n - 1) break;
		}
		ans = min (ans, res);
	}
	printf ("%lld\n", ans);
	return 0;
}

