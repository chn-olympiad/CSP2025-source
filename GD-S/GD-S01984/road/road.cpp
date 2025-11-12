#include <bits/stdc++.h>
#define gc getchar
#define pb push_back
// #define int long long
using namespace std;
const int maxn = 2e6 + 5, mod = 1e9 + 7;
int n, m, k, tot, w[15], a[11][200005], cnt, ecnt;
int read(){
	char c; c = gc(); int fl = 1, res = 0;
	while(c < '0' || c > '9') {if (c == '-') fl = -1; c = gc();}
	while(c >= '0' && c <= '9'){res = (res << 1) + (res << 3) + c - '0'; c = gc();}
	return res * fl;
}
void write(long long x){
	// if (x < 0) putchar('-'), x = -x;
	if (x < 10) putchar(x + '0'); else write(x / 10), putchar(x % 10 + '0');
}
struct Edge{
	int u, v, w;
}e[maxn], e3[maxn];
bool cmp(Edge x, Edge y){
	return x.w < y.w;
}
int fa[maxn];
int find(int x){return (fa[x] == x) ? x : fa[x] = find(fa[x]);}
long long kruskal(bool op){
	sort(e + 1, e + m + cnt + 1, cmp); long long res = 0;
	for (int i = 1; i <= n + tot; i++) fa[i] = i;
	for (int i = 1; i <= m + cnt; i++){
		int x = find(e[i].u), y = find(e[i].v);
		if (x == y) continue; fa[x] = y; res += e[i].w;
		if (!op) e3[++ecnt] = {e[i].u, e[i].v, e[i].w};
	}return res;
}
main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	clock_t st = clock();
	n = read(), m = read(), k = read(); int m2 = 0;
	for (int i = 1; i <= m; i++) e[i] = {read(), read(), read()}; long long ans = kruskal(0); m = ecnt;
	for (int i = 1; i <= k; i++) {w[i] = read(); for (int j = 1; j <= n; j++) a[i][j] = read();} int mx = e[ecnt].w;
	for (int i = 0; i < (1 << k); i++){
		long long now = 0; cnt = tot = 0;
		for (int j = 1; j <= k; j++) if (i & (1 << j - 1)) {
			 now += w[j]; ++tot; for (int l = 1; l <= n; l++) ++cnt, e[m + cnt] = {n + tot, l, a[j][l]};
		}for (int j = 1; j <= m; j++) e[j] = e3[j]; ans = min(ans, now + kruskal(1)); clock_t ed = clock();
		if ((ed - st) * 1.0 / CLOCKS_PER_SEC > 0.98) break;
	}write(ans);
}