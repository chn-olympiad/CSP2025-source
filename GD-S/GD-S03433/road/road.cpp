#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int maxn = 1e4 + 10;
void read(int &n) {
	ll sum = 0;
	while (true) {
		char c = getchar();
		if (c == ' ' || c == '\n') break;
		sum = sum * 10 + (int)(c - '0');
	}
	n = sum;
}
struct Edge {
	int u, v, w, t;
	bool operator < (const Edge &o) const {
		return w < o.w;
	}
};
vector <Edge> e;
int fa[maxn], c[maxn], n, m, k;
bool vis[maxn];
void init(int n) {
	for (int i = 0; i <= n; i++) fa[i] = i;
}
int find(int u) {
	if (fa[u] == u) return u;
	return fa[u] = find(fa[u]);
}
ll kruskal() {
	sort(e.begin(), e.end());
	ll sum = 0;
	int cnt = 0;
	for (auto p : e) {
		int u = p.u, v = p.v, w = p.w, t = p.t;
		u = find(u); v = find(v);
		if (u == v) continue;
		fa[u] = v;
		sum += w;
	}
	return sum;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n); read(m); read(k);
	init(n);
	int u, v, w;
	for (int i = 1; i <= m; i++) {
		read(u); read(v); read(w);
		e.push_back({u, v, w, 0});
	}
	for (int i = 1; i <= k; i++) {
		read(c[i]);
		for (int j = 1; j <= n; j++) {
			read(w);
			e.push_back({i, j, w, 1});
		}
	}
	printf("%lld", kruskal());
	return 0;
}

