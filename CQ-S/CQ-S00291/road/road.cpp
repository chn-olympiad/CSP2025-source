#include <cstdio>
#include <vector>
#include <algorithm>

using std::min;
typedef long long ll;
int c[15], n, m, k;
struct DSU {
	int fa[10015];
	void init() {for (int i = 1; i <= n + k; ++ i) fa[i] = i;}
	int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
	void merge(int u, int v) {fa[find(u)] = find(v);}
} dsu;
ll ans = 1e18;
struct edge {int u, v, w; inline bool operator < (const edge &rhs) const {return w < rhs.w;};} eg[1000005];
std::vector<edge> e[15];
void dfs(int now, ll cost, std::vector<edge> vec) {
	if (now > k) {for (edge i : vec) cost += i.w; ans = min(ans, cost); return;}
	dfs(now + 1, cost, vec), dsu.init();
	std::vector<edge> nxt;
	int i = 0, j = 0;
	while (i < vec.size() && j < e[now].size()) {
		if (vec[i].w < e[now][j].w) dsu.merge(vec[i].u, vec[i].v), nxt.push_back(vec[i]), ++ i;
		else dsu.merge(e[now][j].u, e[now][j].v), nxt.push_back(e[now][j]), ++ j;
		while (i < vec.size() && dsu.find(vec[i].u) == dsu.find(vec[i].v)) ++ i;
		while (j < e[now].size() && dsu.find(e[now][j].u) == dsu.find(e[now][j].v)) ++ j;
	}
	while (i < vec.size()) {
		if (dsu.find(vec[i].u) != dsu.find(vec[i].v)) dsu.merge(vec[i].u, vec[i].v), nxt.push_back(vec[i]);
		++ i;
	}
	while (j < e[now].size()) {
		if (dsu.find(e[now][j].u) != dsu.find(e[now][j].v))
			dsu.merge(e[now][j].u, e[now][j].v), nxt.push_back(e[now][j]);
		++ j;
	}
	dfs(now + 1, cost + c[now], nxt);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++ i) scanf("%d%d%d", &eg[i].u, &eg[i].v, &eg[i].w);
	for (int i = 1; i <= k; ++ i) {
		scanf("%d", c + i);
		for (int j = 1, x; j <= n; ++ j) scanf("%d", &x), e[i].push_back(edge{i + n, j, x});
		std::sort(e[i].begin(), e[i].end());
	}
	std::sort(eg + 1, eg + m + 1);
	std::vector<edge> vec; dsu.init();
	for (int i = 1; i <= m; ++ i)
		if (dsu.find(eg[i].u) != dsu.find(eg[i].v))
			vec.push_back(eg[i]), dsu.merge(eg[i].u, eg[i].v);
	dfs(1, 0, vec); printf("%lld", ans);
	return 0;
}
