#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;

const int N = 1e4 + 6;
const int M = 1e6 + 6;
const int K = 12;
const i64 inf = 1e18;

int n, m, k;

struct edge {
	int u, v;
	i64 w;
};

struct DUS {
	int f[N];

	void init(int n) {
		for (int i = 1; i <= n; i++) {
			f[i] = i;
		}
	}

	int get(int x) {
		return x == f[x] ? x : f[x] = get(f[x]);
	}

	void Merge(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) {
			return;
		}
		f[x] = y;
	}
};

void print_bin(i64 b) {
	std::stack<int> st;
	while (b) {
		st.push(b & 1);
		b >>= 1;
	}
	for (int i = (int)st.size(); i < k; i++) {
		std::cout << 0;
	}
	while (!st.empty()) {
		std::cout << st.top();
		st.pop();
	}
	std::cout << '\n';
}

edge g[M];
edge got[M + K * N];
i64 c[K], a[K][N], ans = inf;
DUS s;

int main() {
    freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	std::cin.tie(nullptr) -> sync_with_stdio(false);

	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; i++) {
		int u, v;
		i64 w;
		std::cin >> u >> v >> w;
		g[i] = {u, v, w};
	}
	for (int i = 1; i <= k; i++) {
		std::cin >> c[i];
		for (int j = 1; j <= n; j++) {
			std::cin >> a[i][j];
		}
	}

	auto work = [&](i64 st) {
		s.init(n + k);
		int cnt = m;
		i64 ret = 0;
		for (int i = 1; i <= m; i++) {
			got[i] = g[i];
		}

		// std::cout << "st: " << st << ' ';
		// print_bin(st);

		while (st) {
			int k = (st & -st);
			st -= k;
			k = std::log2(k) + 1;
			// std::cout << k << ' ';
			ret += c[k];
			for (int i = 1; i <= n; i++) {
				got[++cnt] = {k + n, i, a[k][i]};
			}
		}
		// std::cout << '\n';

		std::sort(got + 1, got + 1 + cnt, [&](edge x, edge y) {
			return x.w < y.w;
		});

		// for (int i = 1; i <= cnt; i++) {
		// 	std::cout << '(' << got[i].u << ',' << got[i].v << ',' << got[i].w << ')' << '\n';
		// }

		// std::cout << "choose: \n";

		for (int i = 1; i <= cnt; i++) {
			int u = got[i].u, v = got[i].v;
			i64 w = got[i].w;
			if (s.get(u) != s.get(v)) {
				ret += w;
				s.Merge(u, v);
				// std::cout << '(' << u << ',' << v << ',' << w << ')' << '\n';
			}
		}
		// std::cout << ret << '\n';
		ans = std::min(ans, ret);
 	};

	for (int st = 0; st < (1 << k); st++) {
		work(st);
	}

	std::cout << ans << '\n';


	return 0;
}