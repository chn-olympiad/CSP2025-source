// 路。
// 看啊，我已经走了这么远。
#include <bits/stdc++.h>
using namespace std;
#define _rep(i,a,b) for(int i = a; i <= b; ++i)
char buf[1<<23],*p1=buf,*p2=buf;
char gc(void) {
	if(p1==p2)p1=buf,p2=buf+fread(buf,1,1<<23,stdin);
	return *p1++;
}
int in(void) {
	int x=0,c=gc();
	while(!isdigit(c))c=gc();
	while(isdigit(c))x=x*10+c-'0',c=gc();
	return x;
}
using ll = long long;
// int in(void) { int x; scanf("%d", &x); return x; }
int n, m, k;
const int kN = 10050;
struct MST {
	int f[kN], cnt; ll tot;
	void init(int n) {
		_rep(i,1,n) f[i] = i; 
		tot = 0, cnt = n;
	}
	int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }
	void add_edge(int u, int v, int w) {
		if(cnt == 1) return;
		u = find(u), v = find(v);
		if(u == v) return;
		f[u] = v, --cnt, tot += w;
	}
} f[1 << 10];
struct Edge {
	int u, v, w;
	bool operator < (const Edge &r) const {
		return w < r.w;
	}
} E[1005000], e[1005000];
int c[10];
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	n = in(), m = in(), k = in();
	_rep(i,1,m) E[i].u = in(), E[i].v = in(), E[i].w = in();
	sort(E + 1, E + 1 + m);
	f[0].init(n); int ecnt = 0;
	_rep(i,1,m) if(f[0].find(E[i].u) != f[0].find(E[i].v)) {
		f[0].add_edge(E[i].u, E[i].v, E[i].w);
		e[++ecnt] = E[i];
	} 
	_rep(i,0,k - 1) {
		c[i] = in();
		_rep(j,1,n) ++ecnt, e[ecnt].u = j, e[ecnt].v = n + i + 1, e[ecnt].w = in();
	}
	_rep(s,0,(1 << k) - 1) {
		f[s].init(n + 10); f[s].cnt = n + __builtin_popcount(s);
		_rep(j,0,k - 1) if(s >> j & 1) f[s].tot += c[j];
	}
	sort(e + 1, e + 1 + ecnt);
	_rep(i,1,ecnt) {
		if(e[i].v <= n) {
			_rep(j,0,(1 << k) - 1) f[j].add_edge(e[i].u, e[i].v, e[i].w);
		} else {
			_rep(j,0,(1 << k) - 1) if(j >> (e[i].v - n - 1) & 1) f[j].add_edge(e[i].u, e[i].v, e[i].w);
		}
	}
	ll ans = 1e18;
	_rep(s,0,(1 << k) - 1) ans = min(ans, f[s].tot);
	printf("%lld\n", ans);
	return 0;
}