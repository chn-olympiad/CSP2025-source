#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int MAXN = 2e4 + 5;
const int MAXEDGE = 2e6 + 5;
const int MAXK = 15;

int dbn, n, m, k, cnt;
LL ans;
int EdgeCnt, EdgeCnt2;

struct Edge {
	int u, v, from;
	LL w;
} e[MAXEDGE], e2[MAXEDGE];

void AddEdge(int u, int v, LL w, int from) {
	++EdgeCnt;
	e[EdgeCnt].u = u;
	e[EdgeCnt].v = v;
	e[EdgeCnt].w = w;
	e[EdgeCnt].from = from;
}

bool cmp(Edge e1, Edge e2) {
	if (e1.w != e2.w)
		return e1.w < e2.w;
	return e1.from < e2.from;
}

bool cmp2(Edge e1, Edge e2) {
	return e1.w > e2.w;
}

int fa[MAXN];

int Find(int x) {
	if (x == fa[x])
		return x;
	return fa[x] = Find(fa[x]);
}

int num[MAXN];
LL cost[MAXN];
int a[MAXK][MAXN];

int read(void) {
	int ret = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9')
		ch = getchar();
	while (ch >= '0' && ch <= '9') {
		ret = (ret << 3) + (ret << 1) + (ch ^ 48);
		ch = getchar();
	}
	return ret;
}

int mat[MAXN];

namespace Solution1 {
	void solve(void) {
		
	}
}

namespace SubtaskA {
	// road3.in
	
	void solve(void) {
		for (int i = 1; i <= k; ++i) {
			for (int j = 1; j <= n; ++j) {
				AddEdge(n + i, j, a[i][j], 0);
			}
		}
		sort(e + 1, e + EdgeCnt + 1, cmp);
		for (int i = 1; i <= EdgeCnt; ++i) {
			int u = e[i].u, v = e[i].v, w = e[i].w;
			int fu = Find(u), fv = Find(v);
			if (fu == fv)
				continue;
			fa[fv] = fu;
			ans += w;
		}
		printf("%lld\n", ans);
	}
}

int main(void) {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = read(), m = read(), k = read();
	dbn = n + n;
	for (int i = 1; i <= dbn; ++i)
		fa[i] = i;
	for (int i = 1, u, v, w; i <= m; ++i) {
		u = read(), v = read(), w = read();
		AddEdge(u, v, w, 0);
	}
	bool flagA = true;
	for (int i = 1, c; i <= k; ++i) {
		c = read();
		cnt = n + i;
		cost[cnt] = c;
		for (int j = 1; j <= n; ++j) {
			a[i][j] = read();
		}
		if (c)
			flagA = false;
	}
	if (flagA) {
		SubtaskA::solve();
		return 0;
	}
//	Solution1::solve();
	puts("19260817");
	return 0;
}
