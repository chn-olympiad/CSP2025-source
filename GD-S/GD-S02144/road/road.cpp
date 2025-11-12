#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define PII pair<int, int>
#define PLL pair<ll, ll>
using namespace std;

constexpr ll inf = (1ll << 62);
constexpr int N = 1e4 + 1;

int n, m, k;
ll ans = 0;
vector<int> c(N);
vector<vector<PLL>> G(N);
array<array<ll, N>, N> a;
vector<int> fa(N);

struct Edge {
	ll u, v, w, id;
};
vector<Edge> edge;

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int a, int b) {
	int x = find(a), y = find(b);
	fa[x] = y;
}

void Kruskal() {
	int cnt = 0;
	for (auto i : edge) {
		ll u = i.u, v = i.v, w = i.w;
		if (find(u) != find(v)) {
			cnt++;
			ans += w;
			merge(u, v);
		}
		if (cnt == n - 1) {
			break;
		}
	}
}

int read() {
	char c = getchar();
	int x = 0, s = 1;
	while (c < '0' || c > '9') {
		if (c == '-') s = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x * s;
}

void solve() {
	iota(fa.begin(), fa.end(), 0);
	n = read();
	m = read();
	k = read();
	for (int i = 0; i < m; i++) {
		int u, v, w;
		u = read();
		v = read();
		w = read();
		u--;
		v--;
		edge.push_back({u, v, w, i});
	}
	for (int i = 0; i < k; i++) {
		c[i] = read();
		for (int j = 0; j < n; j++) {
			a[i][j] = read();
		}
	}
	sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
		return a.w < b.w;
	});
	if (!k) {
		Kruskal();
		printf("%lld", ans);
		return;
	}
	ll res = INT_MAX;
	for (int i = 1; i < (1 << k); i++) {
//		cerr << i << "\n";
		iota(fa.begin(), fa.begin() + n, 0);
		ans = 0;
		int num = m;
		for (int j = 0; j < k; j++) {
			if ((1 << j) & i) {
				ans += c[j];
				for (int p = 0; p < n; p++) {
					for (int l = 0; l < p; l++) {
						edge.push_back({p, l, a[j][p] + a[j][l], num++});
					}
				}
			}
		}
		sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
			return a.w < b.w;
		});
		Kruskal();
		sort(edge.begin(), edge.end(), [&](Edge a, Edge b) {
			return a.id < b.id;
		});
		res = min(res, ans);
		for (int j = 0; j < k; j++) {
			if ((1 << j) & i) {
				for (int p = 0; p < n; p++) {
					for (int l = 0; l < p; l++) {
						edge.pop_back();
					}
				}
			}
		}
	}
	printf("%lld", res);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
