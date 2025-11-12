#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e4, K = 10, M = 2e6;
int n, m, k, ecnt;
int c[K+5];
int fa[1<<K][N+K+5];
LL cost[1<<K];
struct edges {
	int u, v, w, id;
} e[M+5];

bool cmp_edge(edges x, edges y) {
	return x.w < y.w;
}

#define Fath fa[sta]
#define nowfind(u) Find(sta, u)

int Find(int sta, int u) {
	return Fath[u] < 0 ? u : Fath[u] = nowfind(Fath[u]);
}

bool merge(int sta, int u, int v) {
	u = nowfind(u), v = nowfind(v);
	if (u == v) return false;
	if (Fath[u] < Fath[v]) swap(u, v);
	Fath[v] += Fath[u];
	Fath[u] = v;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		e[++ecnt] = {u, v, w, 0};
	}
	for (int i = 1, c; i <= k; i++) {
		cin >> c;
		for (int sta = 0; sta < 1<<k; sta++) {
			if ((sta >> (i-1)) & 1) cost[sta] += c;
		}
		for (int j = 1, x; j <= n; j++) {
			cin >> x;
			e[++ecnt] = {n+i, j, x, i};
		}
	}
//	for (int sta = 0; sta < 1<<k; sta++) cout << cost[sta] << ' ';
//	cout << '\n';
	
	sort(e + 1, e + ecnt + 1, cmp_edge);
	for (int sta = 0; sta < 1<<k; sta++) {
		for (int i = 1; i <= n+k; i++) Fath[i] = -1;
	}
	for (int i = 1; i <= ecnt; i++) {
		for (int sta = 0; sta < 1<<k; sta++) {
			if (e[i].id && (sta >> (e[i].id - 1)) & 1 ^ 1) continue;
			if (merge(sta, e[i].u, e[i].v)) cost[sta] += e[i].w;
		}
	}
	
//	for (int sta = 0; sta < 1<<k; sta++) cout << cost[sta] << ' ';
//	cout << '\n';
	LL ans = 1e18;
	for (int sta = 0; sta < 1<<k; sta++) ans = min(ans, cost[sta]);
	cout << ans; 
	return 0;
}
/*
CSP-S2025 T2
思路由暴力启发而来，即为卡掉排序的 log。
我们可以先对每条进行排序，然后用一种类并行的方法去解决。
排序的时间复杂度为 O(mlogm)，类并行的时间复杂度为 O(m * 2^(k-1) * log(n))，启发式合并卡掉 log。
做出两道题的时间甚至比 CSP2024、NOIP2024 还短。
不要重蹈 NOIP2024 100+100+4+8 的惨剧。
差点遭抽了。 
16:40 可能有说法。
遭抽了。 
*/
