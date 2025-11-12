#include <algorithm>
#include <iostream>

const int N = 1e4 + 7, M = 1e6 + 7, K = 10;
#define rep(i,a,b) for(int i(a);i<=(b);++i)
typedef long long i64;

namespace wyx {

struct edge { short x, y; int w; };
inline bool operator< (const edge& x, const edge& y) {
	return x.w < y.w;
}

struct _dsu {
	int fa[N], siz[N];
	inline void init(int n) {
		for(int i = 1; i <= n; ++i) {
			fa[i] = i, siz[i] = 1;
		}
	}
	int find(int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	}
	inline void merge(int x, int y) {
		x = find(x), y = find(y);
		if(x == y) return ;
		if(siz[x] > siz[y]) {
			fa[y] = x, siz[x] += siz[y];
		} else {
			fa[x] = y, siz[y] += siz[x];
		}
	}
	inline bool iss(int x, int y) {
		return find(x) == find(y);
	}
} dsu;

typedef std::basic_string<edge> graph;
struct Kruskal {
	graph e;
	i64 work(int n) {
		i64 ans = 0; int k = 0;
		dsu.init(n);
		int cnt = 0;
		for(int i = 0; i < (int)e.size(); ++i) {
			auto& [x, y, w] = e[i];
			if(dsu.iss(x, y)) continue;
			ans += w; dsu.merge(x, y);
			e[k++] = e[i];
			++cnt;
		}
		e.resize(k);
		e.shrink_to_fit();
		return ans;
	}
	void apply(const graph& g) {
		int os = e.size();
		e += g;
		std::inplace_merge(e.begin(), e.begin() + os, e.end());
	}
} kru[1<<K];

i64 extra[N];
graph gr[K];
int n, m, k, cost[K];
inline void main() {
	std::cin >> n >> m >> k;
	auto& kun = kru[0];
	short x, y;
	for(int t = m, w; t--; ) {
		std::cin >> x >> y >> w;
		kun.e += {x, y, w};
	}
	for(int i = 0; i < k; ++i) {
		int index = n + i + 1;
		std::cin >> cost[i];
		for(int j = 1, w; j <= n; ++j) {
			std::cin >> w;
			gr[i] += {index, j, w};
		}
		std::sort(gr[i].begin(), gr[i].end());
	}
	std::sort(kun.e.begin(), kun.e.end());
	i64 ans = kun.work(n);
	for(int i = 0; i < k; ++i) {
		int t = 1 << i;
		for(int j = 0; j < t; ++j) {
			int p = j | t;
			extra[p] = extra[j] + cost[i];
			kru[p].e = kru[j].e;
			kru[p].apply(gr[i]);
			ans = std::min(ans, extra[p] + kru[p].work(n + i + 1));
			// std::cerr << (p) << ' ' << ans << "\n";
		}
	}
	std::cout << ans << "\n";
}

};

int main() {
	freopen("road.in", "r", stdin), freopen("road.out", "w", stdout);
	std::ios::sync_with_stdio(0), std::cin.tie(0); std::cout.tie(0);
	wyx::main();
}
