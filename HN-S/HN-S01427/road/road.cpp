#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 1e4 + 5, K = 15, M = 2e6 + 5;
const ll I = 1e16;

struct E {
	int x, y, w;
	bool operator<(const E &e) const {
		return w < e.w;
	}
} e[M];

int n, m, k, a[K][N], c[K], f[N + K];
bool flag;
ll ans;

int Find(int x) {
	return x == f[x] ? x : f[x] = Find(f[x]);
}

void SolA() {
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) {
			e[++m] = {n + i, j, a[i][j]};
		}
	}
	sort(e + 1, e + m + 1), iota(f + 1, f + n + k + 1, 1);
	for (int i = 1, cnt = 0; i <= m; ++i) {
		int x = Find(e[i].x), y = Find(e[i].y);
		if (x != y) {
			ans += e[i].w, ++cnt, f[x] = y;
			if (cnt == n + k - 1) {
				break;
			}
		}
	}
	cout << ans << '\n';
}

void Sol() {
	ans = I;
	for (int t = 0; t < 1 << k; ++t) {
		ll res = 0;
		int tmp = m;
		for (int i = 1; i <= k; ++i) {
			if (!(t >> i - 1 & 1)) {
				continue;
			}
			res += c[i];
			for (int j = 1; j <= n; ++j) {
				e[++m] = {n + i, j, a[i][j]};
			}
		}
		sort(e + 1, e + m + 1);
		int tot = n + __builtin_popcount(t);
		iota(f + 1, f + n + k + 1, 1);
		for (int i = 1, cnt = 0; i <= m; ++i) {
			int x = Find(e[i].x), y = Find(e[i].y);
			if (x != y) {
				res += e[i].w, ++cnt, f[x] = y;
				if (cnt == tot - 1) {
					break;
				}
			}
		}
		m = tmp, ans = min(ans, res);
	}
	cout << ans << '\n';
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) {
		cin >> e[i].x >> e[i].y >> e[i].w;
	}
	for (int i = 1; i <= k; ++i) {
		cin >> c[i];
		flag |= c[i];
		bool b = 1;
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			if (!a[i][j]) {
				b = 0;
			}
		}
		flag |= b;
	}
	if (flag) {
		Sol();
	} else {
		SolA();
	}
	return 0;
}