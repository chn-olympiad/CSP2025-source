#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e4 + 7, M = 1e6 + 7, K = 11;

struct Edge {
	int u, v, w;
	
	inline bool operator < (const Edge &rhs) const {
		return w < rhs.w;
	}
} e[M], ce[K][N];

struct DSU {
	int fa[N];
	
	inline void prework(int n) {
		for (int i = 1; i <= n; ++i)
			fa[i] = i;
	}
	
	inline int find(int x) {
		while (x != fa[x])
			fa[x] = fa[fa[x]], x = fa[x];
		
		return x;
	}
	
	inline void merge(int x, int y) {
		fa[find(x)] = find(y);
	}
} dsu;

int a[K][N], c[K];

int n, m, k;

inline ll Kruskal() {
	sort(e + 1, e + m + 1);
	dsu.prework(n);
	ll res = 0;
	
	for (int i = 1, cnt = 0; i <= m && cnt < n - 1; ++i) {
		int x = dsu.find(e[i].u), y = dsu.find(e[i].v);
		
		if (x != y)
			dsu.merge(x, y), res += e[i].w, ce[0][++cnt] = e[i];
	}
	
	return res;
}

inline ll solve(int s) {
	priority_queue<tuple<int, int, int> > q;
	ll res = 0;
	int cnt = 0;
	dsu.prework(n + k), q.emplace(ce[0][1].w, 0, 1);
	
	for (int i = 1; i <= k; ++i)
		if (s >> (i - 1) & 1)
			q.emplace(-ce[i][1].w, i, 1), res += c[i];
	
	while (!q.empty()) {
		int id = get<1>(q.top()), k = get<2>(q.top());
		q.pop();
		int x = dsu.find(ce[id][k].u), y = dsu.find(ce[id][k].v);
		
		if (x != y)
			dsu.merge(x, y), res += ce[id][k].w, ++cnt;
		
		if (k < (id ? n - 1 : n))
			q.emplace(-ce[id][k + 1].w, id, k + 1);
	}
	
	return res;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	
	for (int i = 1; i <= m; ++i)
		scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
	
	Kruskal();
	
	for (int i = 1; i <= k; ++i) {
		scanf("%d", c + i);
		
		for (int j = 1; j <= n; ++j)
			ce[i][j].u = n + i, ce[i][j].v = j, scanf("%d", &ce[i][j].w);
			
		sort(ce[i] + 1, ce[i] + n + 1);
	}
	
	ll ans = Kruskal();
	
	for (int s = 1; s < (1 << k); ++s)
		ans = min(ans, solve(s));
		
	printf("%lld", ans);
	return 0;
} 
