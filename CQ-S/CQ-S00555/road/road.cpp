#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
typedef long long ll;
inline int read() {int x; return scanf("%d", &x), x;}
namespace solve
{
	const int N = 1e4;
	const int M = 1e6;
	const int K = 10;
	const int E = N + K * N;
	const ll INF = 4e18;
	struct edge
	{
		int u, v, w;
	} e[M + 5], use[N + 5];
	int val[K + 5][N + 5];
	int fa[N + K + 5];
	int get(int u) {return u == fa[u] ? u : fa[u] = get(fa[u]);}
	#define pii std :: pair<int, int>
	#define fi first
	#define se second
	#define mp std :: make_pair
	int t[E + 5];
	struct node
	{
		pii v;
		int ne;
	} ed[E + 5];
	int tong[E + 5], cnt;
	inline void connect(int u, pii v) {ed[cnt] = {v, tong[u]}, tong[u] = cnt ++ ;}
	int main()
	{
		int n = read(), m = read(), k = read();
		for (int i = 1; i <= m; i ++ )
		{
			int u = read(), v = read(), w = read();
			e[i] = {u, v, w};
		}
		for (int i = 1; i <= k; i ++ )
			for (int j = 0; j <= n; j ++ )
				val[i][j] = read();
		std :: sort(e + 1, e + m + 1, [] (edge a, edge b) {return a.w < b.w;});
		for (int i = 1; i <= n; i ++ ) fa[i] = i;
		for (int i = 1, idx = 0; i <= m; i ++ )
		{
			int u = get(e[i].u), v = get(e[i].v), w = e[i].w;
			if (u == v) continue;
			fa[u] = v;
			use[ ++ idx] = e[i];
			t[idx] = w;
		}
		for (int i = 1; i <= k; i ++ )
			for (int j = 1; j <= n; j ++ )
				t[i * n + j - 1] = val[i][j];
		std :: sort(t + 1, t + (k + 1) * n);
		m = std :: unique(t + 1, t + (k + 1) * n) - t - 1;
		for (int i = 1; i < n; i ++ ) use[i].w = std :: lower_bound(t + 1, t + m + 1, use[i].w) - t;
		for (int i = 1; i <= k; i ++ )
			for (int j = 1; j <= n; j ++ )
				val[i][j] = std :: lower_bound(t + 1, t + m + 1, val[i][j]) - t;
		ll res = INF;
		std :: memset(tong, -1, sizeof tong);
		for (int s = 0; s < 1 << k; s ++ )
		{
			for (int i = 1; i < n; i ++ ) connect(use[i].w, mp(use[i].u, use[i].v));
			ll ans = 0;
			for (int i = 1; i <= k; i ++ )
			{
				if (s >> i - 1 & 1 ^ 1) continue;
				ans += val[i][0];
				for (int j = 1; j <= n; j ++ ) connect(val[i][j], mp(n + i, j));
			}
			for (int i = 1; i <= n + k; i ++ ) fa[i] = i;
			for (int i = 1, rem = n - 1 + __builtin_popcount(s); i <= m; i ++ )
			{
				if (!rem) tong[i] = -1;
				for (int &j = tong[i]; ~j; j = ed[j].ne)
				{
					pii hy = ed[j].v;
					int u = get(hy.fi), v = get(hy.se);
					if (u == v) continue;
					fa[u] = v, ans += t[i], rem -- ;
				}
			}
			cnt = 0;
			res = std :: min(res, ans);
		}
		printf("%lld\n", res);
		return 0;
	}
}
int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#endif
	int T = 1;
	while (T -- ) solve :: main();
	return 0;
}