#include <bits/stdc++.h>
#define ll long long
#define gc getchar
#define pc putchar

using namespace std;
const int N = 2e5 + 5, M = 1e6 + 5;

inline ll rd(){
	ll x = 0, f = 1; char c = gc();
	while(! isdigit(c)){if(c == '-')f = - f; c = gc();}
	while(isdigit(c)){x = (x << 3) + (x << 1) + (c ^ 48); c = gc();}
	return x * f;
}
inline void wt(ll x){
	if(x < 0)pc('-'), x = - x; static short st[20], top(0);
	do st[++top] = x % 10, x /= 10; while(x);
	while(top)pc(st[top--] ^ 48);
}

int n, m, k, ff[N];
ll ans, c[12], a[12][N];
struct Edge{int u, v; ll w;}g[M], tr[N], e[N];
inline bool operator < (Edge x, Edge y){return x.w < y.w;}

inline int fd(int x){return x == ff[x] ? x : ff[x] = fd(ff[x]);}
inline ll ksl(Edge E[], int tt, int mm, bool o){
	for(int i = 1; i <= tt; ++i)ff[i] = i;
	int t = 1; sort(E + 1, E + 1 + mm); ll s = 0;
	for(int i = 1; i <= mm; ++i){
		int u = E[i].u, v = E[i].v; ll w = E[i].w;
		if(fd(u) == fd(v))continue;
		int x = fd(u), y = fd(v); ff[x] = ff[y];
		s += w; if(! o)tr[t] = E[i]; if(++t == tt)break;
	}
	return s;
}

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = rd(); m = rd(); k = rd();
	for(int i = 1, u, v, w; i <= m; ++i)
		u = rd(), v = rd(), w = rd(), g[i] = {u, v, w};
	ans = ksl(g, n, m, 0); for(int i = 1; i <= k; ++i){
		c[i] = rd(); for(int j = 1; j <= n; ++j)a[i][j] = rd();
	}
	for(int i = 1; i < 1 << k; ++i){
		for(int j = 1; j < n; ++j)e[j] = tr[j];
		int s = 0, t = n - 1; ll res = 0;
		for(int j = 0; j < k; ++j)if(i >> j & 1){
			res += c[j + 1]; ++s; for(int q = 1; q <= n; ++q)
				e[++t] = {n + s, q, a[j + 1][q]};
		}
		ans = min(ans, res + ksl(e, n + s, t, 1));
	}
	return wt(ans), 0;
}