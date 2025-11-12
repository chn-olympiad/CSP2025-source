#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+20;
set<pair<int, pair<int, int>>>roads;
int n, m, k, c[20], a[20][N];
int fa[N];
int findf(int a) {
	if (fa[a] == a)return a;
	return fa[a] = findf(fa[a]);
}
bool use[20];
int prim() {
	int cnt = 0;
	int ans = 0;
	while (!roads.empty()) {
		auto edge = *roads.begin();
		auto u = edge.second.first, v = edge.second.second, w = edge.first;
		roads.erase(roads.begin());
		if (findf(u) == findf(v)) {
			continue;
		}
		ans += w;
		fa[u] = fa[v];
	}
	return ans;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		roads.insert(make_pair(w, make_pair(u, v)));
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			roads.insert(make_pair(a[i][j] + c[i], make_pair(i + n, j)));
		}
	}
	printf("%d", prim());
}