#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <type_traits>
#ifdef DEBUG
# define debug(...) fprintf(stderr, __VA_ARGS__)
#else
# define debug(...) ((void)0)
#endif
using std::min; using std::max; using std::abs;
#define For(i, s, t) for (int i = (s); i <= (t); ++i)
#define roF(i, t, s) for (int i = (t); i >= (s); --i)
namespace FastI {
	char buf[1 << 20], *p1=nullptr, *p2=nullptr;
	inline char gc() { if (p1 == p2) p2 = (p1=buf) + fread(buf, 1, sizeof buf, stdin); return *p1++; }
	inline void in(char &x) { do x = gc(); while (x == ' ' || x == '\n' || x == '\r'); }
	inline void in(int &x) {
		char ch = gc();
		while (ch < '0' || ch > '9') ch = gc();
		for (x = ch ^ '0', ch = gc(); ch >= '0' && ch <= '9'; ch = gc())
			x = (x << 3) + (x << 1) + (ch ^ '0');
	}
	inline void in(char *s) {
		do *s = gc(); while (*s == ' ' || *s == '\n' || *s == '\r');
		do *(++s) = gc(); while (*s != ' ' && *s != '\n' && *s != '\r');
		*s = '\0';
	}
} using FastI::in;

constexpr int N = 10005, M = 1000005, K = 10, Inf = 0x7fffffff;

struct Edge {
	int u, v, w;
	inline bool operator< (const Edge &rhs) const {
		return w < rhs.w;
	}
} edgs[M], selected[N];

struct EdgeNode {
	int to, nxt, w;
} e[N<<1];
int head[N];
inline void addedg(const Edge &edg) {
	e[++head[0]] = EdgeNode {edg.v, head[edg.u], edg.w}; head[edg.u] = head[0];
	e[++head[0]] = EdgeNode {edg.u, head[edg.v], edg.w}; head[edg.v] = head[0];
}

namespace DSU {
	int fa[N];
	inline void init(int n) { For (i, 1, n) fa[i] = i; }
	inline int getfa(int u) {
		int v=u, tp;
		while (u ^ fa[u]) u = fa[u];
		while (v ^ u) tp = fa[v], fa[v] = u, v = tp;
		return u;
	}
	inline bool merge(int u, int v) {
		u = getfa(u), v = getfa(v);
		return (u ^ v) ? (fa[v] = u) : false;
	}
}
int fa[N], flen[N];
void dfs(int u, int pre) {
	for (int i = head[u], v; i; i = e[i].nxt) {
		if ((v = e[i].to) == pre) continue;
		fa[v] = u, flen[v] = e[i].w;
		dfs(v, u);
	}
}
inline long long kruskal_rebuild_tree(int n, int m) {
	DSU::init(n);
	std::sort(edgs+1, edgs+1 + m);
	int cnt = 1; long long sum = 0;
	for (int i = 1; cnt < n; i++) {
		if (i <= n) debug("%d %d\n", DSU::getfa(edgs[i].u), DSU::getfa(edgs[i].v));
		if (DSU::merge(edgs[i].u, edgs[i].v))
			selected[++cnt] = edgs[i], sum += edgs[i].w;
	}
	For (i, 1, n)
		addedg(selected[i]);
	dfs(1, 0);
	For (i, 2, n) debug("fa=%d w=%d\n", fa[i], flen[i]);
	return sum;
}

struct City {
	int c, a[N], mn, mn2;
	int f[N]; // 节点 i 想从这个乡村连接另外一个城市 的最小路径长
	inline int& operator[](int p) {return a[p];}
	inline int& operator()() {return c;}
	inline int& operator()(int p) {return f[p];}
} ct[K];

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
#ifdef DEBUG
	freopen("road.err", "w", stderr);
#endif
	int n, m, k;
	in(n), in(m), in(k);
	For (i, 1, m) in(edgs[i].u), in(edgs[i].v), in(edgs[i].w);
	long long without_rural = kruskal_rebuild_tree(n, m);
	For (i, 0, k-1) {
		in(ct[i]());
		ct[i].mn = ct[i].mn2 = Inf / 2;
		For (j, 1, n) {
			in(ct[i][j]);
			if (ct[i][j] < ct[i].mn) { // 预处理最大次大
				ct[i].mn2 = ct[i].mn;
				ct[i].mn = ct[i][j];
			}
			else if (ct[i][j] < ct[i].mn2)
				ct[i].mn2 = ct[i][j];
		}
		For (j, 1, n) {
			if (ct[i][j] == ct[i].mn) ct[i](j) = ct[i][j] + ct[i].mn2;
			else ct[i](j) = ct[i][j] + ct[i].mn;
		}
	}
	long long max_reduce = 0;
	For (st, 0, (1<<k)-1) {
		long long red = 0;
		For (i, 0, k-1)
			if (st >> i & 1)
				red -= ct[i](); // 改造乡村
		For (j, 2, n) {
			int mn = Inf;
			For (i, 0, k-1)
				if (st >> i & 1)
					mn = min(mn, ct[i](fa[j]));
			if (mn < flen[j]) red += flen[j] - mn;
			debug("node=%d: pre %d, new %d\n", j, flen[j], mn);
		}
		debug("%lld\n", red);
		max_reduce = max(max_reduce, red);
	}
	debug("%lld %lld\n", without_rural, max_reduce);
	printf("%lld\n", without_rural - max_reduce);
	return 0;
}
