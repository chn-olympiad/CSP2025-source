#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 100;

int n, m, k;
int c[10], a[10][N];

struct edge {
	int u, v, w;
};

bool operator <(edge a, edge b) {
	return a.w < b.w;
}

struct DSU {
	int fa[N];
	void init(int n) {
		iota(fa + 1, fa + n + 1, 1);
	}
	int getfa(int x) { 
		return (x ^ fa[x]) ? fa[x] = getfa(fa[x]) : x;
	}
	bool merge(int x, int y) {
		x = getfa(x), y = getfa(y);
		return x == y ? 0 : (fa[x] = y, 1);
	}
} F;

vector<edge> e[10], T[1 << 10];

vector<edge> merge(vector<edge> &a, vector<edge> &b) {
	vector<edge> c;
	int i = 0, j = 0;
	while (i < a.size() || j < b.size()) {
		if (j == b.size() || (i < a.size() && a[i] < b[j])) {
		//	assert(i < a.size());
			c.push_back(a[i++]);
		} else {
		//	assert(j < b.size());
			c.push_back(b[j++]);
		}
	}
	return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	cin >> n >> m >> k;
	
	vector<edge> E;
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		E.push_back({u, v, w});
	}
	sort(E.begin(), E.end());
	
	F.init(n);
	ll ans = 0;
	for (auto [u, v, w]: E) {
		if (F.merge(u, v)) T[0].push_back({u, v, w}), ans += w;
	}	
	
	for (int i = 0; i < k; ++i) {
		cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			e[i].push_back({n + 1 + i, j, a[i][j]});
		}
		sort(e[i].begin(), e[i].end());
	}
	
	for (int S = 1; S < (1 << k); ++S) {
		vector<edge> E = merge(T[S & S - 1], e[__builtin_ctz(S)]);
		F.init(n + k); ll s = 0;
		for (auto [u, v, w]: E) {
			if (F.merge(u, v)) T[S].push_back({u, v, w}), s += w;
		}
		for (int i = 0; i < k; ++i) if (S >> i & 1) s += c[i];
		ans = min(ans, s);
	}
	
	cout << ans << endl;

	return 0;
}