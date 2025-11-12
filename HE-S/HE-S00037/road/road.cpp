#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 1e18;
const int MAXN = 1010050;
int n, m, k, c[15], val[15][MAXN];
struct edge {
	int u, v, w, tk;
} e[MAXN], g[MAXN];
bool cmp(edge a,edge b) {
	return a.w < b.w;
}
int fa[MAXN];
int find(int x){
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void merge(int u, int v) {
	u = find(u), v = find(v);
	if (u == v) return;
	fa[u] = v;
}
bool add[MAXN];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1;i <= m; i++) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[i].u = u, e[i].v = v, e[i].w = w, e[i].tk = -1;
	}
	for(int i = 1; i <= k; i++) {
		scanf("%d", &c[i]);
		for(int j = 1; j <= n; j++) {
			scanf("%d", &val[i][j]);
		}
	}
	sort(e + 1, e + m + 1, cmp);
	for(int i = 1; i <= m; i++) fa[i] = i;
	ll cur = 0;
	int gc = 0;
	for(int i = 1; i <= m; i++) {
		int u = e[i].u, v = e[i].v, w = e[i].w;
		int fu = find(u), fv = find(v);
		if (fu != fv) {
			merge(fu, fv);
			cur += w;
			g[++gc] = e[i];
		}
	}
	if (k == 0) {
		printf("%lld", cur);
		return 0;
	}
	for(int i = 1;i <= gc; i++) {
		//erase i
		int u = g[i].u, v = g[i].v, w = g[i].w, wh = -1;
		ll mn = INF;
		for(int j = 1; j <= k; j++) {
			if (c[j] > w) continue;
			for(int p = 1; p <= n; p++) {
				if (p == u) continue;
				ll r = val[j][p] + val[j][u], d = c[j];
				if (add[j]) d = 0;
				if (r + d < mn) mn = r + d, wh = j;
			}
		}
		if (mn < w) {
			cur = cur - w + mn;
			if (wh != -1 && !add[wh]) {
				add[wh] = true;
			} 
		}
	}
	printf("%lld", cur);
	return 0;
}
