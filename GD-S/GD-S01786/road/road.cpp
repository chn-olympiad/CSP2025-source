#include <bits/stdc++.h>
using namespace std;
using LL = long long;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
namespace FastIO {
	char gc() {
		static char buf[1 << 20], *p1, *p2;
		if (p1 == p2) p1 = buf, p2 = buf + fread(buf, 1, 1 << 20, stdin);
		return p1 == p2 ? EOF : *(p1++);
	}
	template <typename T> void read(T &x) {
		char ch; bool op = 0; x = 0;
		do ch = gc(), op |= ch == '-'; while (ch < '0' || ch > '9');
		do x = x * 10 + (ch & 15), ch = gc(); while (ch >= '0' && ch <= '9');
		if (op) x = -x;
	}
	template <typename T, typename ...U> void read(T &x, U &...y) { read(x), read(y...); }
	template <typename T> void write(T x, char ed = '\n') {
		static int stk[100]; int tp = 0;
		if (x < 0) putchar('-'), x = -x;
		do stk[++tp] = x % 10, x /= 10; while (x);
		for (; tp; --tp) putchar(stk[tp] | 48);
		putchar(ed);
	}
	template <typename T, typename ...U> void write(T x, U ...y) { write(x, ' '), write(y...); }
}
using namespace FastIO;

bool Mst;
const int MAXN = 1e4+5;
const int MAXM = 1e6+5;
struct Edge {
	int u, v, w;
	Edge() = default;
	Edge(int _u, int _v, int _w) { u = _u, v = _v, w = _w; }
} E[MAXM], F[20][MAXN]; 
int n, m, k, vis[20], pos[20];
LL cost[20];
namespace DSU {
	int fa[MAXN], siz[MAXN];
	void init() { for (int i = 1; i <= n; ++i) fa[i] = i, siz[i] = 1; }
	int findfa(int x) { return fa[x] == x ? x : fa[x] = findfa(fa[x]); }
	int merge(int x, int y) {
		x = findfa(x), y = findfa(y);
		if (x == y) return 0;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y], fa[y] = x;
		return x;
	}
}

bool Med;

int main() {
	assert(freopen("road.in", "r", stdin));
	assert(freopen("road.out", "w", stdout));
	// fprintf(stderr, "%f\n", (&Mst - &Med) / 1048576.0);
	read(n, m, k);
	if (n == 1) return puts("0"), 0;
	for (int i = 1; i <= m; ++i) read(E[i].u, E[i].v, E[i].w);
	sort(E + 1, E + m + 1, [](Edge a, Edge b) { return a.w < b.w; });
	DSU::init();
	for (int i = 1, num = 0; i <= m; ++i)
		if (DSU::merge(E[i].u, E[i].v)) F[0][++num] = E[i];
	for (int i = 1; i <= k; ++i) {
		read(cost[i]);
		for (int x = 1; x <= n; ++x) read(F[i][x].w), F[i][x].v = x;
		sort(F[i] + 1, F[i] + n + 1, [](Edge a, Edge b) { return a.w < b.w; });
		for (int j = 2; j <= n; ++j) F[i][j].u = F[i][1].v;
		cost[i] += F[i][1].w, vis[i] = 0;
	}
	LL mn = 4e18;
	for (int S = 0; S < (1 << k); ++S) {
		DSU::init();
		LL sum = 0;
		pos[0] = 1;
		for (int i = 1; i <= k; ++i)
			if (S >> (i - 1) & 1) sum += cost[i], pos[i] = 2;
		while (pos[0] < n) {
			int p = 0; LL val = F[0][pos[0]].w;
			for (int i = 1; i <= k; ++i) {
				if ((S >> (i - 1) & 1) ^ 1) continue;
				if (pos[i] > n) continue;
				LL cur = F[i][pos[i]].w;
				if (cur < val) p = i, val = cur;
			}
			int id = pos[p]++;
			if (DSU::merge(F[p][id].u, F[p][id].v)) sum += val;
		}
		mn = min(mn, sum);
	}
	write(mn);
	return 0;
}
