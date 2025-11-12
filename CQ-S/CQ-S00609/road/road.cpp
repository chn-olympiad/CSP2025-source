#include <bits/stdc++.h>

#define i64 long long

#define pii pair<int, int>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using namespace std;

inline char nc() {
	static char buf[1000000], *p = buf, *q = buf;
	return (p == q) && (q = (p = buf) + fread(buf, 1, 1000000, stdin), p == q) ? EOF : *p++;
}

inline int Read() {
	int ret = 0, g = 0;
	char c = nc();
	while(c < '0' || c > '9') g |= (c == '-'), c = nc();
	while('0' <= c && c <= '9') ret = 10 * ret + c - '0', c = nc();
	return ret * (g ? -1 : 1);
} 

const int N = 10000 + 5, M = 1000000 + 5, K = 10 + 5;

int n, m, k, f[N + K], c[K], vis[N + K];
struct Node {
	int u, v, w;
}ed[M], e[M];

bool cmp(Node x, Node y) {return x.w < y.w; }

int Getf(int x) {return f[x] == x ? x : f[x] = Getf(f[x]); }

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = Read(), m = Read(), k = Read();
	for(int i = 1; i <= m; ++ i) ed[i].u = Read(), ed[i].v = Read(), ed[i].w = Read();
	sort(ed + 1, ed + m + 1, cmp);
	for(int i = 1; i <= n; ++ i) f[i] = i;
	int tc = 0;
	i64 ans = 0;
	for(int i = 1; i <= m; ++ i) {
		int u = ed[i].u, v = ed[i].v, fx = 0, fy = 0;
		if((fx = Getf(u)) != (fy = Getf(v))) {
			f[fx] = fy, ans += ed[i].w;
			e[++ tc] = ed[i];
		}
	}
	m = tc;
	
	for(int i = 1; i <= k; ++ i) {
		c[i] = Read();
		for(int j = 1; j <= n; ++ j) {
			int x = Read();
			tc ++, e[tc].u = i + n, e[tc].v = j, e[tc].w = x;
		}
	}
	
	sort(e + 1, e + tc + 1, cmp);
	
	for(int T = 1; T < (1 << k); ++ T) {
		i64 tmp = 0;
		for(int i = 1; i <= n + k; ++ i) f[i] = i, vis[i] = 0;
		for(int i = 0; i < k; ++ i) {
			if((T >> i) & 1) tmp += c[i + 1], vis[i + 1 + n] = 1; 
		}
		for(int i = 1; i <= n; ++ i) vis[i] = 1; 
		for(int i = 1; i <= tc; ++ i) {
			int u = e[i].u, v = e[i].v, fx = 0, fy = 0;
			if(!vis[u] || !vis[v]) continue;
			if((fx = Getf(u)) != (fy = Getf(v))) {
				f[fx] = fy, tmp += e[i].w;
			}
			if(tmp > ans) break;
		}
		ans = min(ans, tmp);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}
/*
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込 
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込込込込込込込込込込込込
込込込込込込込込込込込込込込込込込
込込込込込込込込込込込
込込込込込込込
込込込込
込込込
込込
込
*/ 
