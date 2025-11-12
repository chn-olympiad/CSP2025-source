#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
const int K = 12;
const int MS = (1 << 10) + 5;
const int M = 1e6 + 5;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f3fll;

char buf[1 << 20], *p1, *p2;
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 20, stdin), p1 == p2) ? EOF : *p1++)
//#define gc() getchar()
void read(int &x) {
	x = 0;
	char ch = gc();
	while (ch < '0' || ch > '9') ch = gc();
	while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = gc(); 
}

int n, m, k;
struct Edge {
	int u, v, w;
	Edge (int _u = 0, int _v = 0, int _w = 0) :
		u(_u), v(_v), w(_w) {}
} ed[M], res[N * K];
bool cmp(Edge x, Edge y) {
	return x.w < y.w;
} 
int cst[K] = {0};

int cnt = 0;
int p[N] = {0}, sz[N] = {0};
void init(int _sz) {
	for (int i = 1; i <= _sz; i++) p[i] = i, sz[i] = 1;
}
int fnd(int x) {
	return p[x] == x ? x : p[x] = fnd(p[x]);
}
void unn(int x, int y) {
	x = fnd(x), y = fnd(y);
	if (x == y) return;
	if (sz[x] < sz[y]) swap(x, y); 
	p[y] = x;
	sz[x] += sz[y];
} 

void Kruskal() {
	sort(ed + 1, ed + m + 1, cmp);
	init(n);
	for (int i = 1; i <= m; i++)
		if (fnd(ed[i].u) != fnd(ed[i].v)) {
			res[++cnt] = ed[i];
			unn(ed[i].u, ed[i].v);
		}
}

ll cal(int S) {
	ll ans = 0ll;
	for (int i = 1; i <= k; i++) if (S >> (i - 1) & 1) ans += cst[i];
	init(n + k);
	for (int i = 1; i <= cnt; i++) {
		if (res[i].u > n && (~S >> (res[i].u - n - 1) & 1)) continue;
		if (fnd(res[i].u) != fnd(res[i].v)) {
			ans += res[i].w;
			unn(res[i].u, res[i].v);
		}
	}
	return ans;
} 

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n), read(m), read(k);
	for (int i = 1; i <= m; i++) read(ed[i].u), read(ed[i].v), read(ed[i].w);
	Kruskal();
	for (int i = 1; i <= k; i++) {
		read(cst[i]);
		for (int j = 1, x; j <= n; j++) {
			read(x);
			res[++cnt] = Edge(n + i, j, x);
		}
	}
	sort(res + 1, res + cnt + 1, cmp);
	ll ans = inf;
	for (int i = 0; i < (1 << k); i++) ans = min(ans, cal(i));
	printf("%lld\n", ans);
	return 0;
} 
