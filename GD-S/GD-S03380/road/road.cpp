#include <bits/stdc++.h>

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

using i128 = __int128;
using u128 = unsigned __int128;

struct DSU {
	int n;
	std::vector<int> siz, fa;

	DSU(int n_ = 0) {
		init(n_);
	}

	void init(int n_) {
		n = n_;
		siz.assign(n, 1);
		fa.assign(n, 0);
		std::iota(fa.begin(), fa.end(), 0);
	}

	int find(int x) {
		for (; x != fa[x]; ) {
			x = fa[x] = fa[fa[x]];
		}
		return x;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		int fx = find(x), fy = find(y);
		if (fx == fy) {
			return false;
		}
		if (siz[fx] < siz[fy]) {
			std::swap(fx, fy);
		}
		fa[fy] = fx;
		siz[fx] += siz[fy];
		siz[fy] = 0;
		return true;
	}

	int size(int x) {
		return siz[find(x)];
	}
};

int32_t main() {
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m, k;
	std::cin >> n >> m >> k;

	std::vector<std::tuple<int, int, i64>> edge(m);
	for (int i = 0; i < m; i++) {
		int u, v; i64 w;
		std::cin >> u >> v >> w;
		edge[i] = {--u, --v, w};
	}

	std::vector<std::vector<i64>> a(k, std::vector<i64> (n));
	std::vector<i64> c(k);
	for (int i = 0; i < k; i++) {
		std::cin >> c[i];
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}

	std::sort(edge.begin(), edge.end(), [&](auto const& lhs, auto const& rhs) -> bool {
		return std::get<2>(lhs) < std::get<2>(rhs);
	});

	std::vector<std::tuple<int, int, i64>> e;
	DSU dsu(n);
	e.reserve(n - 1);
	for (auto zip : edge) {
		auto u = std::get<0>(zip);
		auto v = std::get<1>(zip);
		auto w = std::get<2>(zip);
		if (dsu.merge(u, v)) {
			e.push_back(zip);
		}
	}

	i64 ans = 1LL << 60;
	for (int i = 0; i < n; i++) {
		auto E = e;
		i64 sum = 0;
		for (int j = 0; j < k; j++) {
			if (i >> j & 1) {
				sum += c[j];
				for (int u = 0; u < n; u++) {
					E.push_back({n + j, u, a[j][u]});
				}
			}
		}
		std::sort(E.begin(), E.end(), [&](auto const& lhs, auto const& rhs) -> bool {
			return std::get<2>(lhs) < std::get<2>(rhs);
		});

		DSU dsu(n + k);
		int cnt = 0;
		for (auto zip : E) {
			auto u = std::get<0>(zip);
			auto v = std::get<1>(zip);
			auto w = std::get<2>(zip);
			if (dsu.merge(u, v)) {
				sum += w;
				++cnt;
			}
		}

		if (dsu.size(0) == n + __builtin_popcount(i)) {
			ans = std::min(ans, sum);
		}
	}
	std::cout << ans << "\n";

	return 0;
}

