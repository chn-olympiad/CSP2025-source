#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 10100;
int n, m, k;
int fa[N], c[N];
vector<array<int, 3>> E, e[N];

int find(int x) {
	while (x != fa[x]) x = fa[x] = fa[fa[x]];
	return x;
}

ll calc(int s) {
	for (int i = 1; i <= n + k; i++) {
		fa[i] = i;
	}
	set<array<int, 3>> st;
	if (n > 1)
		st.insert({e[k][0][0], k, 0});
	ll res = 0;
	int nn = n;
	for (int i = 0; i < k; i++) if (s>>i&1) {
		st.insert({e[i][0][0], i, 0});
		nn++;
		res += c[i];
	}
	int tot = 0;
	while (!st.empty()) {
		auto [w, id, p] = *st.begin();
		st.erase(st.begin());
		int u = e[id][p][1], v = e[id][p][2];
		// printf("%d %d %d\n", u, v, w);
		if (find(u) != find(v)) {
			tot++;
			fa[find(v)] = find(u);
			res += w;
			// printf("%d %d %d %d %d\n", u, v, w, id, p);
		}
		if (tot == nn - 1) break;
		p++;
		// printf("%d %d %d %d\n", tot, n, p, (int)e[id].size());
		if (p < (int)e[id].size()) {
			st.insert({e[id][p][0], id, p});
		}
	}
	return res;
}

int main() {
	freopen("road.in", "r", stdin);	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		E.push_back({w, u, v});
	}
	for (int i = 0; i < k; i++) {
		scanf("%d", &c[i]);
		for (int j = 1, a; j <= n; j++) {
			scanf("%d", &a);
			e[i].push_back({a, n + i + 1, j});
		}
		sort(e[i].begin(), e[i].end());
	}
	sort(E.begin(), E.end());
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (auto [w, u, v] : E) {
		if (find(u) != find(v)) {
			fa[find(v)] = find(u);
			e[k].push_back({w, u, v});
		}
	}
	// calc(1); return 0;
	ll ans = 1ll<<59;
	for (int s = 0; s < (1 << k); s++) {
		// printf("%d %lld\n", s, calc(s));
		ans = min(ans, calc(s));
	}
	printf("%lld\n", ans);
	return 0;
}