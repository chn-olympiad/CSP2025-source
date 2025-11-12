#include <algorithm>
#include <cstring>
#include <iostream>

#define PROBLEM_NAME "road"
#define MULTIPLE_TEST 0

template<int N>
struct DSU {
	int fa[N], sz[N];
	DSU() { }
        inline void Init() {
		for (int i = 1; i < N; i++)
			fa[i] = i, sz[i] = 1;
	}
	inline int Find(int u) {
		return fa[u] == u ? u : fa[u] = Find(fa[u]);
	}
	inline bool Merge(int u, int v) {
		if ((u = Find(u)) == (v = Find(v)))
			return false;
		if (sz[u] > sz[v]) std::swap(u, v);
		sz[fa[u] = v] += sz[u];
		return true;
	}
};

struct Edge {
	int u, v, w;
	inline bool operator< (const Edge &rhs) {
		return w < rhs.w;
	}
};

template<typename D>
inline long long MST(D &dsu, Edge *el, int m) {
	dsu.Init();
	int cur = 1;
	long long res = 0;
	for (int i = 1; i <= m; i++) {
		if (dsu.Merge(el[i].u, el[i].v)) {
			res += el[i].w;
			std::swap(el[cur++], el[i]);
		}
	}
	return res;
}

struct Solver {
	struct In {
		int n, m, k;
		int u[1000010];
		int v[1000010];
		int w[1000010];
		int c[20], a[20][10010];
		In() {
			std::cin >> n >> m >> k;
			for (int i = 1; i <= m; i++)
				std::cin >> u[i] >> v[i] >> w[i];
			for (int i = 1; i <= k; i++) {
				std::cin >> c[i];
				for (int j = 1; j <= n; j++)
					std::cin >> a[i][j];
			}
		}
	} in;
	struct Out {
		long long ans;
		~Out() { std::cout << ans << '\n'; }
	} out;
	DSU<10020> dsu;
	Edge elm[1000010];
	Edge elo[20][10010];
	Edge el[20][20010];
	Solver() {}
	inline void search(int i, int tot, long long cur) {
		if (i == in.k + 1) return;
		search(i + 1, tot, cur);
		cur += in.c[i];
		std::merge(el[tot] + 1, el[tot] + in.n + tot - 1, 
			   elo[i] + 1, elo[i] + in.n + tot, 
			   el[tot + 1] + 1);
		out.ans = std::min(out.ans, cur + 
			MST(dsu, el[tot + 1], in.n * 2 + tot * 2 - 3));
		search(i + 1, tot + 1, cur);
	}
	inline void Work() {
		for (int i = 1; i <= in.m; i++)
			elm[i] = {in.u[i], in.v[i], in.w[i]};
		std::sort(elm + 1, elm + in.m + 1);
		out.ans = MST(dsu, elm, in.m);
		memcpy(el[1] + 1, elm + 1, sizeof(Edge) * (in.n - 1));
		for (int i = 1; i <= in.k; i++) {
			for (int j = 1; j <= in.n; j++)
				elo[i][j] = {in.n + i, j, in.a[i][j]};
			std::sort(elo[i] + 1, elo[i] + in.n + 1);
		}
		search(1, 1, 0);
	}
};

int main() {
	static uint8_t space[sizeof(Solver)];
	freopen(PROBLEM_NAME ".in", "r", stdin);
	freopen(PROBLEM_NAME ".out", "w", stdout);
	// Overriding stdin/stdout, evil but working...
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
#if MULTIPLE_TEST == 1
	std::cin >> T;
#else
	T = 1;
#endif
	while (T--) {
		Solver *solver = new (space) Solver();
	       	solver -> Work();
		solver -> ~Solver();
		if (T) memset(space, 0, sizeof(space));
	}
	return 0;
}
#undef PROBLEM_NAME
#undef MULTIPLE_TEST