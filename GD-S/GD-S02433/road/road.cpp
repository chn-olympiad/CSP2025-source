#include <bits/stdc++.h>

using namespace std;
#define i64 long long

const int N = 1e4 + 10;
const int M = 1e6 + 10;

struct Edge {
	int u, v, w;
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
} e[M];

int n, m, k, fa[N], c[15], a[15][N];

int fr(int u) {
	return fa[u]==u ? u : fa[u]=fr(fa[u]);
}

i64 kruskal() {
	sort(e + 1, e + m + 1);
	int cnt = 0;
	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		int u = fr(e[i].u), v = fr(e[i].v);
		if (u != v) {
			fa[u] = v;
			cnt++, ans += e[i].w;
		}
		if (cnt == n-1) {
			break;
		}
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		cin >> e[i].u >> e[i].v >> e[i].w;
	}
	cout << kruskal() << "\n";
	return 0;
}
