#include <bits/stdc++.h>
using namespace std;

template<class T>
bool chmax(T& a, const T& b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

struct edge {
	int u, v, w;
	inline edge() {}
	inline edge(int u, int v, int w) : u(u), v(v), w(w) {}
	inline bool operator<(const edge& b) const {
		return w < b.w;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<edge> e;
	for (int i = 0, u, v, w; i < m; i++) {
		cin >> u >> v >> w;
		u--, v--;
		e.emplace_back(u, v, w);
	}
	
	vector<int> f(n);
	iota(f.begin(), f.end(), 0);
	auto find = [&](int x) {
		while (x != f[x]) x = f[x] = f[f[x]];
		return x;
	};
	
	sort(e.begin(), e.end());
	long long ans = 0;
	for (int i = 0; i < m; i++) {
		int u = find(e[i].u), v = find(e[i].v);
		if (u == v) continue;
		f[v] = u;
		ans += e[i].w;
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int t = 1;
	while (t--) solve();
	return 0;
}
