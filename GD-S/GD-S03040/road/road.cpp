#include <bits/stdc++.h>

#define i64 std::int64_t
#define i32 std::int32_t

#define MAX_N (size_t)(1e4 + 10)

#define INF (1e9 + 7)

// using namespace std;

i32 n, m, k;

struct Edge {
	i32 v;
	i64 w;
};

std::vector<Edge> graph1[MAX_N];

i64 graph2[1010][1010], c[MAX_N], a[11][MAX_N];
i64 fa[MAX_N], size[MAX_N];

i64 ans;

void solve1() {
	for (i32 i = 1; i <= m; ++i) {
		i32 u, v, w;
		std::cin >> u >> v >> w;
		
	}
}

i32 getf(i32 u) {
	if (fa[u] != u) {
		fa[u] = getf(fa[u]);
		return fa[u];
	} else {
		return u;
	}
}

void add(i32 u, i32 v) {
	i32 fu = getf(u);
	i32 fv = getf(v); 
	if (fu != fv) {
		size[fu] += size[fv];
		fa[fv] = fu; 
	}
}

void solve2() {
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j <= n; ++j) {
			graph2[i][j] = INF;
		}
//		d[i] = INF;
//		f[i] = INF;
		fa[i] = i;
		size[i] = 1;
	}
	for (i32 i = 1; i <= m; ++i) {
		i64 u, v, w;
		std::cin >> u >> v >> w;
		graph2[u][v] = graph2[v][u] = std::min(graph2[u][v], w); 
	}
	
	for (i32 i = 1; i <= k; ++i) {
		std::cin >> c[i];
		for (i32 j = 1; j <= n; ++j) {
			std::cin >> a[i][j];
		}
		for (i32 j = 1; j <= n; ++j) {
			for (i32 k = 1; k < j; ++k) {
				graph2[j][k] = graph2[k][j] = std::min(graph2[j][k], c[i] + a[i][j] + a[i][k]);
			} 
		}
	}
	
	struct Edge {
		i32 u, v; 
	};
	
	std::vector<Edge> es; 
	
	for (i32 i = 1; i <= n; ++i) {
		for (i32 j = 1; j < i; ++j) {
			es.push_back((Edge){i, j});
		}
	}
	
	std::sort(es.begin(), es.end(), [](const Edge& lft, const Edge& rgt) -> bool {
		return graph2[lft.u][lft.v] < graph2[rgt.u][rgt.v];
	});
	
	for (auto e: es) {
		i32 uf = getf(e.u), vf = getf(e.v);
		if (uf != vf) {
			ans += graph2[e.u][e.v];
			add(e.u, e.v);
			if (size[getf(e.u)] == n) {
				break;
			}
		}
	}
	
//	for (i32 i = 1; i <= n; ++i) {
//		std::cout << fa[i] << " " << size[i] << "\n"; 
//	}
	
	std::cout << ans << "\n";
	
//	struct MT {
//		i64 u;
//		i64 fa;
//	};
//	
//	std::queue<MT> q;
//	q.push((MT){1, -1});
//	d[1] = 0;
//	f[1] = 0;
//	while (!q.empty()) {
//		MT node = q.front();
//		q.pop();
//		for (i32 i = 1; i <= n; ++i) {
//			if (i == node.u || i == node.fa) continue;
//			if (graph2[node.u][i] == INF) continue;
//			if (d[i] == INF) {
//				q.push((MT){i, node.u});
//				d[i] = graph2[node.u][i];
//				f[i] = f[node.u] + 1;
//			} else {
//				if (f[i] <= f[node.u] && graph2[node.u][i] < d[node.u]) {
//					d[node.u] = graph2[node.u][i];
//					
//				}
//			}
//		}
//	}
} 

i32 main(i32 argc, char* argv[]) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);

	std::cin >> n >> m >> k;

	if (k <= 0) {
		solve1();
	}
	
	if (n <= 1000) {
		solve2();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

