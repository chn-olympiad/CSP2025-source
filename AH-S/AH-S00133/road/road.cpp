#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = (l); i <= (r); ++ i)
#define per(i, l, r) for (int i = (l); i >= (r); -- i)
using namespace std;
const int N = 1e4 + 10, M = 1e6 + 10;
struct edge_to {
	int to, w;
};
struct edge {
	int u, v, w;
	bool operator < (const edge &other) const {
		return w < other.w;
	}
}e[M];
int n, m, k, c[20], a[20][N];
vector <edge_to> g[N];
namespace _1_to_4 {
	int f[N];
	void init() {
		rep(i, 1, n) {
			f[i] = i;
		}
		sort(e + 1, e + m + 1);
	}
	int find(int x) {
		if (f[x] == x) {
			return x;
		}
		return f[x] = find(f[x]);
	}
	void merge(int u, int v) {
		int fu = find(u), fv = find(v);
		f[fu] = fv;
	}
	int solve() {
		int cnt = 0, ans = 0;
		rep(i, 1, m) {
			if (find(e[i].u) != find(e[i].v)) {
				merge(e[i].u, e[i].v);
				ans += e[i].w;
				if (++ cnt == n - 1) {
					break;
				}
			}
		}
		return ans;
	}
};
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m >> k;
	rep(i, 1, m) {
		cin >> e[i].u >> e[i].v >> e[i].w;
		g[e[i].u].push_back({e[i].v, e[i].w});
		g[e[i].v].push_back({e[i].u, e[i].w});
	}
	rep(i, 1, k) {
		cin >> c[i];
		rep(j, 1, n) {
			cin >> a[i][j];
		}
	}
	if (k == 0) {
		_1_to_4::init();
		cout << _1_to_4::solve();
		return 0;
	}
	cout << 0;
	return 0;
}
