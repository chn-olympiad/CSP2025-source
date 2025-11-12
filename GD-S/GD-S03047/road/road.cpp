#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 1e4 + 5, M = 1e6 + 5;
int n, m, k;
ll ans;
struct Edge {
	int to, w, nxt;
} e[N << 1];
int head[N], cnt;
void add(int u, int v, int w) {
	e[++cnt] = {v, w, head[u]};
	head[u] = cnt;
}
struct node {
	int u, v, w;
	bool operator< (const node &x) const {return w < x.w;}
} E[M];
int FA[N];
inline int find(int x) {
	if (FA[x] != x) FA[x] = find(FA[x]);
	return FA[x];
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
	sort(E + 1, E + m + 1);
	for (int i = 1; i <= n; i++) FA[i] = i;
	for (int i = 1; i <= m; i++) {
		int p = find(E[i].u), q = find(E[i].v);
		if (p == q) continue;
		FA[p] = q;
		add(E[i].u, E[i].v, E[i].w); add(E[i].v, E[i].u, E[i].w);
		ans += E[i].w;
	}
	if (!k) {printf("%lld", ans); return 0;}
	
	return 0;
}
