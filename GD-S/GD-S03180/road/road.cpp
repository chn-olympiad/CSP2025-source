/* TODO (#1#): Remove the debug macro */
//#define DEBUG_AEQUILUM
#include <iostream>
#include <algorithm>
#define int long long 
// pts 48 (1-6, 9-10, 13-14, 17-18)

namespace {
	constexpr int MAX_N = 11451;
	constexpr int MAX_M = 1145140;
	
	struct Edge {
		int u, v, w;
		bool operator<(const Edge& edge) const {
			return w < edge.w;
		}
	};
	
	int n, m, k;
	Edge edges[MAX_M];
	int fa[MAX_N];
	int c[MAX_N];
	int m_cpy;
	
	int find(int u) {
		if (fa[u] == u) return fa[u];
		return fa[u] = find(fa[u]);
	}
	
	void merge(int u, int v) {
		fa[find(u)] = find(v);
	}
	
	int kruskal() {
		int cst = 0;
		std::sort(edges + 1, edges + 1 + m_cpy);
		for (int i = 1; i <= m_cpy; ++i) {
			auto edge = edges[i];
			if (find(edge.u) != find(edge.v)) {
				merge(edge.u, edge.v);
				cst += edge.w; 
			}
		}
		return cst;
	}
}

signed main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
	
#ifndef DEBUG_AEQUILUM
	std::freopen("road.in", "r", stdin);
	std::freopen("road.out", "w", stdout);
#endif
	
	std::cin >> n >> m >> k;
	for (int i = 1; i <= m; ++i) std::cin >> edges[i].u >> edges[i].v >> edges[i].w;
	m_cpy = m;
	for (int i = 1; i <= k; ++i) {
		std::cin >> c[i];
		for (int j = 1; j <= n; ++j) {
			std::cin >> edges[++m_cpy].w;
			edges[m_cpy].u = n + i;
			edges[m_cpy].v = j;
		}
	}
	
	for (int i = 1; i <= n + k; ++i) fa[i] = i;

	std::cout << kruskal() << std::endl;

	std::cout.flush();
	return 0;
}
