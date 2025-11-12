#include <bits/stdc++.h>
#define int long long 
const int N = 1e4 + 15, M = 2e6 + 1; 
using namespace std; 
int n, m, k, ans; 
struct Edge {
	int u, v, w; 
} e[M];
inline bool operator < (Edge P, Edge Q) {
	return P.w < Q.w; 
}
int c[11][N], fa[N], sz[N]; 
inline int read() {
	int x = 0, f = 1; char ch = getchar(); 
	while(ch < '0' && ch > '9') {if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar(); 
	return x; 
}
inline int Find(int x) {
	return fa[x] ^ x ? fa[x] = Find(fa[x]) : x; 
}
inline int Min(int x, int y) {
	if(x == -1) return y; 
	return min(x, y); 
}
bool vis[N]; 
inline void work(int tt) {
	for(int i = 1; i <= k; ++i) vis[n + i] = 0; 
	int sum = 0, nn = n, cnt = 0; 
	for(int i = 1; i <= k; ++i)
		if(tt & (1LL << (i - 1))) {
			sum += c[i][0]; ++nn; 
			vis[n + i] = 1; 
		}
	for(int i = 1; i <= nn; ++i) fa[i] = i, sz[i] = 1; 
	for(int i = 1, fu, fv; i <= m; ++i) {
		if(cnt == nn - 1) break; 
		if(!vis[e[i].u] || !vis[e[i].v]) continue; 
		fu = Find(e[i].u); fv = Find(e[i].v); 
		if(fu == fv) continue; 
		if(sz[fu] > sz[fv]) fa[fv] = fu, sz[fu] += sz[fv]; 
		else fa[fu] = fv, sz[fv] += sz[fu]; 
		++cnt; sum += e[i].w; 
	}
	ans = Min(ans, sum); 
	return ; 
}
inline void solve() {
	n = read(); m = read(); k = read(); 
	for(int i = 1; i <= m; ++i) e[i].u = read(), e[i].v = read(), e[i].w = read(); 
	for(int i = 1; i <= k; ++i) {
		c[i][0] = read(); 
		for(int j = 1; j <= n; ++j) c[i][j] = read(); 
	}
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= n; ++j)
			e[++m] = {n + i, j, c[i][j]}; 
	sort(e + 1, e + m + 1); 
	for(int i = 1; i <= n; ++i) vis[i] = 1; 
	ans = -1; int fw = 1 << k; 
	for(int tt = 0; tt < fw; ++tt) work(tt); 
	cout << ans << "\n"; 
	return ; 
}
signed main() {
	freopen("road.in", "r", stdin); 
	freopen("road.out", "w", stdout); 
	ios::sync_with_stdio(false); 
	cin.tie(0); cout.tie(0); 
	solve(); 
	return 0; 
}
