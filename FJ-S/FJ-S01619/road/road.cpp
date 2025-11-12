#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
struct Edge {
	long long u, v, w;
	bool operator < (const Edge b) {
		return w < b.w;
	}
};
vector<Edge> edge, add[N], tmp;
long long n, m, k, ans, fa[N], cst[N], ret = INT_MAX;
bitset<N> vis[N];
long long find(long long x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin.tie(nullptr) -> sync_with_stdio(false);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i ++) {
		cin >> u >> v >> w;
		tmp.push_back({u, v, w});
	}
	for (int i = 1, p; i <= k; i ++) {
		cin >> p, cst[i] = p;
		for (int j = 1, w; j <= n; j ++)
			cin >> w, add[i].push_back({j, n + i, w});
	}
	for (int i = 0, cnt; i < (1 << k); i ++) {
		edge = tmp;
		cnt = ans = 0;
		for (int j = k - 1; ~j; j --)
			if (i >> j & 1) {
				ans += cst[j + 1];
				for (int a = 0; a < add[j + 1].size(); a ++)
					edge.push_back(add[j + 1][a]);
			}
		for (int i = 1; i <= n + k; i ++)
			fa[i] = i;
		sort(edge.begin(), edge.end());
		for (int j = 0; j < edge.size(); j ++) {
			if (find(edge[j].u) != find(edge[j].v)) {
				ans += edge[i].w;
				fa[find(edge[j].u)] = find(edge[j].v);
				cnt += edge[j].u <= n;
				cnt += edge[j].v <= n;
			}
			if (cnt == 2 * n - 2) {
				ret = min(ret, ans);
				break;
			}
		}
	}
	cout << ret;
	return 0;
}

