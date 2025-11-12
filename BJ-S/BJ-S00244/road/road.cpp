/**
 * @brief CSP-S 2025
 *        Problem B. road
 * @author BJ-S00244    liuli688
*/
#include <bits/stdc++.h>
using std::cin;
using std::cout;
typedef long long ll;

const int N = 1e4 + 20, M = 2e6 + 10;
ll ans = 0x3fffffffffffffff;
bool reb[20], A = true;
int n, m, k, c[20];

class Edge {
public:
	int u, v, w;
	bool operator < (const Edge& rhs) const {
		return w < rhs.w;
	}
} G[M];

int fa[N], height[N];
int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u, int v) {
	int p = find(u), q = find(v);
	if (p == q)
		return ;
	if (height[p] < height[q]) {
		fa[p] = fa[q];
		height[q] = std::max(height[q], height[p] + 1);
	} else {
		fa[q] = fa[p];
		height[p] = std::max(height[p], height[q] + 1);
	}
}
ll kruskal(int ex) {
    for (int i = 1; i <= n + k; ++i)
        fa[i] = i, height[i] = 1;
	ll res = 0;
	int cnt = 0;
	for (int i = 1; cnt < n + ex - 1 && i <= m; ++i) {
		if (G[i].u > n && !reb[G[i].u - n])
			continue;
		if (G[i].v > n && !reb[G[i].v - n])
			continue;
        if (find(G[i].u) == find(G[i].v))
            continue;
        merge(G[i].u, G[i].v);
		++cnt;
		res += G[i].w;
	}
	return res;
}

void dfs(int dep, int ex, ll exc) {
	if (dep == k + 1) {
		ans = std::min(ans, kruskal(ex) + exc);
		return ;
	}
	reb[dep] = false;
	dfs(dep + 1, ex, exc);
	reb[dep] = true;
	dfs(dep + 1, ex + 1, exc + c[dep]);
}

int main(int argc, const char *argv[]) {
	cin.tie(nullptr) -> sync_with_stdio(false);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; ++i)
		cin >> G[i].u >> G[i].v >> G[i].w;
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		A &= (c[i] == 0);
		bool flag = false;
		for (int j = 1; j <= n; ++j) {
			++m;
			G[m].u = n + i;
			G[m].v = j;
			cin >> G[m].w;
			if (G[m].w == 0)
				flag = true;
		}
		A &= flag;
	}
	std::sort(G + 1, G + m + 1);
	if (A) {
        for (int i = 1; i <= k; ++i)
            reb[i] = true;
		cout << kruskal(k) << '\n';
	} else {
		dfs(1, 0, 0);
		cout << ans << '\n';
	}
	return 0;
}

///passwd: Ren5Jie4Di4Ling5%
