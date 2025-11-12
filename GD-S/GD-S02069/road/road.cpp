#include <bits/stdc++.h>

using i64 = long long;
using i128 = __int128;

template<int MAXN>
struct DSU {
	std::array<int, MAXN> fa, siz;

	DSU() {}
	DSU(int n) {
		init(n);
	}

	void init(int n) {
		std::iota(fa.begin() + 1, fa.begin() + n + 1, 1);
		for (int i = 1; i <= n; i++) {
			siz[i] = 1;
		}
	}

	int find(int x) {
		if (x != fa[x]) {
			fa[x] = find(fa[x]);
		}
		return fa[x];
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) {
			return false;
		}
		if (siz[x] > siz[y]) {
			std::swap(x, y);
		}
		fa[x] = y;
		siz[y] += siz[x];
		return true;
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

struct Path {
	int u, v, w;

	bool operator < (const Path &t) {
		return w < t.w;
	}
};

void R() {
	int n, m, k;
	std::cin >> n >> m >> k;

	constexpr int M = 1e6 + 10;
	static std::array<Path, M> path;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		std::cin >> u >> v >> w;
		path[i] = {u, v, w};
	}
	std::sort(path.begin() + 1, path.begin() + m + 1);

	constexpr int N = 1e4 + 10;
	constexpr int K = 15;
	static DSU<N + K> dsu(n);
	std::vector<Path> edges;
	for (int i = 1; i <= m; i++) {
		int u = path[i].u, v = path[i].v, w = path[i].w;
		if (dsu.merge(u, v)) {
			edges.push_back({u, v, w});
		}
	}

	static std::array<int, K> c;
	static std::array<std::vector<std::pair<int, int>>, K> a;
	for (int i = 0; i < k; i++) {
		std::cin >> c[i];
		a[i].resize(n);		
		for (int j = 0; j < n; j++) {
			int x;
			std::cin >> x;
			a[i][j] = {x, j};
		}
		std::sort(a[i].begin(), a[i].end());
		std::reverse(a[i].begin(), a[i].end());
	}

	constexpr int inf = 2e9;
	constexpr i64 infll = 1e18;
	i64 res = infll;
	for (int i = 0; i < 1 << k; i++) {
		std::vector<std::vector<std::pair<int, int>>> road;
		i64 sum = 0;
		for (int j = 0; j < k; j++) {
			if (i >> j & 1) {
				road.push_back(a[j]);
				sum += c[j];
			}
		}
		dsu.init(n + k);
		for (auto it : edges) {
			int u = it.u, v = it.v, w = it.w;
			while (true) {
				int mn = inf, u_ = 0, v_ = 0;
				for (unsigned int j = 0; j < road.size(); j++) {
					while (!road[j].empty() && dsu.same(n + j + 1, road[j].back().second)) {
						road[j].pop_back();
					}
					if (!road[j].empty() && road[j].back().first < mn) {
						mn = road[j].back().first;
						u_ = n + j + 1;
						v_ = road[j].back().second;
					}
				}
				if (mn > w) {
					break;
				}
				sum += mn;
				dsu.merge(u_, v_);
			}
			if (dsu.merge(u, v)) {
				sum += w;
			}
		}
		res = std::min(res, sum);
	}

	std::cout << res << "\n";
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T = 1;
	// std::cin >> T;
	while (T--) {
		R();
	}
}