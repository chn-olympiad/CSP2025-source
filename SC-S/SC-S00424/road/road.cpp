#include <iostream>
#include <algorithm>
#define ll long long
#define INF64 1000000000000000000
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++)
using namespace std;

struct Edge {
	int u, v, w;
	friend bool operator<(Edge x, Edge y) {
		return x.w < y.w;
	}
};

char *p1, *p2, buf[1000000];
int read() {
	int x = 0;
	char c = getchar();
	while (c < '0' or c > '9') {
		c = getchar();
	}
	while (c >= '0' and c <= '9') {
		x = x * 10 + (c & 15), c = getchar();
	}
	return x;
}

int n, m, k, fa[10011], c[10], w[10][10001];
bool flag = true;
Edge e[2000001], tmp[2000001];

int find(int u) { return fa[u] == u ? u : fa[u] = find(fa[u]); }

struct SubtaskA {
	void start() {
		for (int i = 1; i <= n + k; ++i) {
			fa[i] = i;
		}
		for (int i = 0; i < k; ++i) {
			for (int j = 1; j <= n; ++j) {
				e[++m] = {n + i + 1, j, w[i][j]};
			}
		}
		sort(e + 1, e + m + 1), n += k;
	}
	void calc() {
		ll ans = 0;
		start();
		for (int i = 1, t = 0; i <= m; ++i) {
			if (t == n - 1) {
				break;
			}
			int u = find(e[i].u), v = find(e[i].v);
			if (u != v) {
				++t, ans += e[i].w, fa[v] = u;
			}
		}
		printf("%lld\n", ans);
	}
} subA;

struct Subtask {
	int tot, cnt;
	Edge edge[2000001];
	ll Kruskal() {
		ll res = 0;
		for (int i = 1; i <= n + k; ++i) {
			fa[i] = i;
		}
		stable_sort(edge + 1, edge + tot + 1);
		for (int i = 1, t = 0; i <= tot; ++i) {
			if (t == cnt - 1) {
				break;
			}
			int u = find(edge[i].u), v = find(edge[i].v);
			if (u != v) {
				++t, res += edge[i].w, fa[v] = u;
			}
		}
		return res;
	}
	void calc() {
		ll ans = INF64;
		for (int S = 0; S < (1 << k); ++S) {
			ll val = 0;
			tot = m, cnt = n;
			for (int i = 0; i < k; ++i) {
				if (S >> i & 1) {
					val += c[i], ++cnt;
					for (int j = 1; j <= n; ++j) {
						e[++tot] = {n + i + 1, j, w[i][j]};
					}
				}
			}
			for (int i = 1; i <= tot; ++i) {
				edge[i] = e[i];
			}
			ans = min(ans, Kruskal() + val);
		}
		printf("%lld\n", ans);
	}
} sub;

void prepare() {
	for (int i = 1; i <= n; ++i) {
		fa[i] = i;
	}
	stable_sort(tmp + 1, tmp + m + 1);
	for (int i = 1, t = 0; i <= m; ++i) {
		int u = find(tmp[i].u), v = find(tmp[i].v);
		if (u != v) {
			e[++t] = tmp[i], fa[u] = v;
		}
	}
	m = n - 1;
}

void init() {
	n = read(), m = read(), k = read();
	for (int i = 1; i <= m; ++i) {
		tmp[i] = {read(), read(), read()};
	}
	prepare();
	for (int i = 0; i < k; ++i) {
		bool f = false;
		c[i] = read(), flag &= !c[i];
		for (int j = 1; j <= n; ++j) {
			w[i][j] = read(), f |= !w[i][j];
		}
		flag &= f;
	}
}

void calculate() {
	if (flag) {
		subA.calc();
	} else {
		sub.calc();
	}
}

void solve() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	init(), calculate();
}

int main(){
	solve();
	return 0;
}