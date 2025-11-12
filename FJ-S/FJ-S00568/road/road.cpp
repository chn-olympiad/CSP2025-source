#include <cstdio>
#include <algorithm>

typedef unsigned long long data_t;

struct Edge {
	int u, v;
	data_t w;
} edges[2000005];

int c[20];

bool operator<(Edge l, Edge r) {
	return l.w < r.w;
}

int fa[20005];

int root(int x) {
	if (fa[x]==x) return x;
	return fa[x]=root(fa[x]);
}

void u(int x, int y) {
	fa[root(x)]=fa[root(y)];
}

bool q(int x, int y) {
	return root(x)==root(y);
}

void init(int n) {
	for (int i = 1 ; i <= n ; i ++) {
		fa[i]=i;
	}
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1 ; i <= m ; i ++) {
		scanf("%d%d%llu", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	for (int j = 1 ; j <= k ; j ++) {
		scanf("%d", &c[j]);
		for (int i = 1 ; i <= n ; i ++) {
			scanf("%llu", &edges[++m].w);
			edges[m].u=n+j;
			edges[m].v=i;
		}
	}
	std::sort(edges+1, edges+m+1);
	init(n+k);
	data_t cost = 0;
	for (int i = 1 ; i <= m ; i++) {
		Edge e=edges[i];
		if (!q(e.u, e.v)) {
			cost += e.w;
			u(e.u, e.v);
		}
	}
	printf("%llu\n", cost);
	return 0;
}
