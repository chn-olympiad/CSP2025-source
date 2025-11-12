#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 1e4 + 50, M = 1e6 + 10;
int n, m, k;
array<int, 20> c, cnt;
bool flag;

struct Edge {
	int u, v, w;

	Edge(int u, int v, int w) : u(u), v(v), w(w) {}

	bool operator<(Edge o) {
	 return w < o.w;
	}	 
};

vector<Edge> edg0, edg00;
array<vector<Edge>, 20> edg; 

struct DSU {
	array<int, N> f, d;

	int fd(ll x) {
		while(x != f[x]) {
			x = f[x] = f[f[x]];
		}
		return x;
	}

	void add(int x, int y) {
		x = fd(x), y = fd(y);
		if(x == y) {
			return;
		}
		if(d[x] < d[y]) {
			swap(x, y);
		}
		f[y] = x, d[x] += d[x] == d[y];
	}

	void reset() { 
		for(int i = 1; i <= n + k; i++) {
			f[i] = i, d[i] = 1;
		}
	}
} dsu;

ll kruskal0() {
	ll ans = 0;
	dsu.reset();
	for(Edge i : edg00) {
		if(dsu.fd(i.u) == dsu.fd(i.v)) {
			continue;
		}
		dsu.add(dsu.fd(i.u), dsu.fd(i.v));
		ans += i.w;
		edg[0].push_back(i);
	}
	return ans;
}

ll kruskal() {
	ll ans = 0;
	dsu.reset();
	for(Edge i : edg0) {
		if(dsu.fd(i.u) == dsu.fd(i.v)) {
			continue;
		}
		dsu.add(dsu.fd(i.u), dsu.fd(i.v));
		ans += i.w;
	}
	return ans;
}

void init_data() {
	cin >> n >> m >> k;
	for(int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		edg00.emplace_back(u, v, w);
	}
	sort(edg00.begin(), edg00.end());
	for(int i = 1; i <= k; i++) {
		cin >> c[i];
		for(int j = 1, edg_val; j <= n; j++) {
			cin >> edg_val;
			edg[i].emplace_back(n + i, j, edg_val);
		}
		sort(edg[i].begin(), edg[i].end());
	}
}

ll solve_x(int x) {
	edg0.clear();
	cnt.fill(0);
	flag = 1;
	while(flag) {
		flag = 0;
		int mn = 2e9, mp = 0;
		for(int i = 0; i <= k; i++) {
			if(~(x >> i) & 1) {
				continue;
			}
			if(cnt[i] == n - (i == 0)) {
				continue;
			}
			flag = 1;
			if(edg[i][cnt[i]].w < mn) {
				mn = edg[i][cnt[i]].w, mp = i;
			}
		}
		if(flag) {
			edg0.push_back(edg[mp][cnt[mp]++]);
		}
	}
	return kruskal();
}

ll solve() {
	ll ans = kruskal0(), sum;
	for(int i = 3; i < (1 << (k + 1)); i += 2) {
		sum = 0;
		for(int j = 1; j <= k; j++) {
			if((i >> j) & 1) {
				sum += c[j];
			}
		}
		ans = min(ans, solve_x(i) + sum);
	}
	return ans;
}

int main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	init_data();
	cout << solve() << '\n';
}
