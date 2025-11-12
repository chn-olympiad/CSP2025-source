#include <cstdio>
#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

using ll = long long;

constexpr int MAXN = 2e4 + 10;
constexpr int MAXM = 1e6 + 10;

struct Edge {
	int u, v;
	ll w;

	Edge() {}
	Edge(int u, int v, ll w) : u{u}, v{v}, w{w} {}

	friend bool operator < (const Edge& a, const Edge& b) {
		return a.w < b.w;
	}
};

int n, m, K;
std::vector<Edge> basic_edge;
std::array<std::array<ll, MAXN>, 15> a;

void input() {
	scanf("%d%d%d", &n, &m, &K);
	int u, v; ll w;
	for(int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &u, &v, &w);
		basic_edge.push_back(Edge(u, v, w));
	}
	for(int i = 1; i <= K; i++) {
		for(int j = 0; j <= n; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
}

class Ufind {
public:
	std::array<int, MAXN> fa;

	Ufind() : fa{{}} {}

	void initial(int n) {
		for(int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}
};

ll ans;
std::vector<Edge> use_edge;
std::vector<Edge> tmp_edge;
Ufind uf;

ll Kruscal(int msk) {
	ll tmp = 0;
	int new_node = 0;
	use_edge = basic_edge;
	for(int i = 1; i <= K; i++) {
		if((msk >> (i-1)) & 1) {
			tmp += a[i][0];
			if(tmp > ans) return 1e18;
			new_node++;
			for(int j = 1; j <= n; j++) {
				use_edge.push_back(Edge(n+i, j, a[i][j]));
			}
		}
	}
	uf.initial(n + K);
	std::sort(use_edge.begin(), use_edge.end());
//	for(auto& edge: use_edge) {
//		std::cout << edge.u << ' ' << edge.v << ' ' << edge.w << std::endl;
//	}
	int cnt = 0;
	for(auto& edge : use_edge) {
		int u = uf.find(edge.u);
		int v = uf.find(edge.v);
		if(u != v){
			uf.fa[u] = v;
			cnt++;
			tmp += edge.w;
			if(msk == 0) {
				tmp_edge.push_back(edge);
			}
			if(tmp > ans) return 1e18;
		}
		if(cnt == n+new_node-1) break;
	}
	if(msk == 0) basic_edge = tmp_edge;
	if(cnt < n+new_node-1) return 1e18;
//	std::cout << msk << ' ' << tmp << std::endl;
	return tmp;
}

void work() {
	ans = 1e18;
	for(int msk = 0; msk < (1 << K); msk++) {
		ans = std::min(ans, Kruscal(msk));
	}
	printf("%lld\n", ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out","w",stdout);
	input();
	work();
	return 0;
}
