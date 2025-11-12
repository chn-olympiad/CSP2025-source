#include <bits/stdc++.h>
#define ll long long
#define inf 2147483647 //9223372036854775807
using namespace std;

inline ll rd() {
	ll x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') { if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
	return x * f;
}

struct Edge {
	ll u, v, w;
} E[1000006], e[200005], g[200005];
int fa[200005];
ll c[12], a[12][10004];

int fd(int x) { return fa[x] == x ? x : fa[x] = fd(fa[x]); }
bool cmp(Edge x, Edge y) { return x.w < y.w; }
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n = rd(), m = rd(), k = rd(), N = (1ll << k) - 1, tot = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) 
		E[i].u = rd(), E[i].v = rd(), E[i].w = rd();
	for(int i = 1; i <= k; i++) {
		c[i] = rd();
		for(int j = 1; j <= n; j++) a[i][j] = rd();
	}
	sort(E + 1, E + m + 1, cmp);
	for(int i = 1; i <= m; i++) {
		int u = fd(E[i].u), v = fd(E[i].v);
		if(u == v) continue;
		fa[u] = v;
		g[++tot] = E[i];
		ans += E[i].w;
	}
	for(int s = 1; s <= N; s++) {
		tot = n - 1;
		ll sum = 0;
		int cnt = n;
		for(int i = 1; i < n; i++) e[i] = g[i];
		for(int i = 1; i <= n + k; i++) fa[i] = i;
		for(int i = 1; i <= k; i++) if(s & (1 << (i - 1))) {
			sum += c[i], cnt++;
			for(int j = 1; j <= n; j++) {
				if(a[i][j] < e[n - 1].w) {
					e[++tot].u = n + i;
					e[tot].v = j;
					e[tot].w = a[i][j];
				}
			}
		}
		sort(e + 1, e + tot + 1, cmp);
		for(int i = 1; i <= tot; i++) {
			int u = fd(e[i].u), v = fd(e[i].v);
			if(u == v) continue;
			fa[u] = v;
			sum += e[i].w;
			if(--cnt == 1) break;
		}
		ans = min(ans, sum);
	}
	cout << ans; 
	return 0;
}
/*

*/

