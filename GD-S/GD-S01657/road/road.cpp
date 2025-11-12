#include <bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
#define md make_pair
#define gc getchar
#define pc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair<int, int> pii;
ll read()
{
	ll res = 0, f = 1; char ch = gc();
	while (ch < '0' || ch > '9') f = (ch == '-' ? -1 : f), ch = gc();
	while (ch >= '0' && ch <= '9') res = (res << 1) + (res << 3) + (ch ^ 48), ch = gc();
	return res * f;
}
void write(ll x)
{
	if (x < 0) pc('-'), x = -x;
	if (x > 9) write(x / 10);
	pc(x % 10 + '0');
}
void writech(ll x, char ch) { write(x), pc(ch); }
const int N = 1e4 + 5, M = 1e6 + 5, K = 15;
const int NN = 1e3 + 5;
struct Edge {
	int u, v, w;
} edge[M], tmp[M], e[M];
bool cmp(Edge x, Edge y) { return x.w < y.w; }
int fa[N];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
ll c[K], a[K][N]; ll b[NN][NN];
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = read(), m = read(), k = read();
	for (int i = 1; i <= m; i++)
	{
		int u = read(), v = read(), w = read();
		edge[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++)
	{
		c[i] = read();
		for (int j = 1; j <= n; j++) a[i][j] = read();
	}
	for (int i = 1; i <= n + k; i++) fa[i] = i;
	if (k == 0)
	{
		sort(edge + 1, edge + m + 1, cmp);
		int cnt = 0; ll ans = 0;
		for (int i = 1; i <= m; i++)
		{
			int s = find(edge[i].u), t = find(edge[i].v);
			if (s != t)
			{
				fa[s] = t;
				cnt++;
				ans += edge[i].w;
			}
			if (cnt == n - 1) break;
		}
		write(ans);
		return 0;
	}
	for (int i = 1; i <= m; i++) tmp[i] = edge[i];
	ll ans = 2e18;
	for (int S = 0; S < (1 << k); S++)
	{
		ll sum = 0;
		for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) b[i][j] = 2e18;
		for (int i = 1; i <= m; i++) b[edge[i].u][edge[i].v] = edge[i].w;
		for (int j = 1; j <= k; j++)
		{
			if (S & (1 << (j - 1)))
			{
				sum += c[j];
				for (int u = 1; u <= n; u++)
					for (int v = 1; v <= n; v++)
						b[u][v] = min(b[u][v], a[j][u] + a[j][v]);
			}
		}
		int cur = 0;
		for (int u = 1; u <= n; u++)
			for (int v = 1; v <= n; v++)
				tmp[++cur] = {u, v, b[u][v]};
		sort(tmp + 1, tmp + cur + 1, cmp);
//		for (int i = 1; i <= cur; i++) cout << tmp[i].u << " " << tmp[i].v << " " << tmp[i].w << endl;
		for (int i = 1; i <= n; i++) fa[i] = i;
		int cnt = 0;
		for (int i = 1; i <= cur; i++)
		{
			int s = find(tmp[i].u), t = find(tmp[i].v);
			if (s != t)
			{
				fa[s] = t;
				cnt++;
				sum += tmp[i].w;
			}
			if (cnt == n - 1) break;
		}
		ans = min(ans, sum);
	}
	write(ans);
//	sort(edge + 1, edge + m + 1, cmp);
//	int cnt = 0;
//	for (int i = 1; i <= m; i++)
//	{
//		int u = edge[i].u, v = edge[i].v, w = edge[i].w;
//		int s = find(u), t = find(v);
//		if (s != t)
//		{
//			fa[s] = t;
//			tmp[++cnt] = {u, v, w};
//		}
//		if (cnt == n - 1) break;
//	}
//	ll ans = 1e18;
//	for (int S = 0; S < (1 << k); S++)
//	{
//		for (int i = 1; i <= cnt; i++) e[i] = tmp[i];
//		ll sum = 0;
//		for (int j = 1; j <= k; j++)
//		{
//			if (S & (1 << (j - 1)))
//			{
//				cout << j << " ";
//				sum += c[j];
//				for (int i = 1; i <= cnt; i++)
//				{
//					int u = e[i].u, v = e[i].v;
//					e[i].w = min(e[i].w, a[j][u] + a[j][v]);
//				}
//			}
//		}
//		cout << endl;
//		cout << sum << endl;
//		for (int i = 1; i <= cnt; i++) cout << e[i].u << " " << e[i].v << " " << e[i].w << endl;
//		for (int i = 1; i <= cnt; i++) sum += e[i].w;
//		ans = min(ans, sum);
//	}
//	write(ans);
	return 0;
}
/*
4 4 2
1 2 1
2 3 2
3 4 3
4 1 4
0 1 2 3 4
0 4 3 2 1
*/
