#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define mst(f, i) memset(f, i, sizeof f)
#define pb push_back
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr);
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
namespace fastio{
	template<typename T> inline void read(T &t){
		T x = 0, f = 1;
		char c = getchar();
		while(!isdigit(c)){
			if(c == '-') f = -f;
			c = getchar();
		}
		while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
		t = x * f;
	}
	template<typename T, typename ... Args> inline void read(T &t, Args &...args){
		read(t), read(args...);
	}
	void write(int x){printf("%d", x);}
	void writes(int x){printf("%d ", x);}
	void writeln(int x){printf("%d\n", x);}
	void write(ll x){printf("%lld", x);}
	void writes(ll x){printf("%lld ", x);}
	void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); for(int tCase = 1; tCase <= T; ++tCase)
const int N = 2e4 + 5, M = 2e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int n, m, k;
struct edge{
	int op;
	int u, v, w;
	edge(int _op = 0, int _u = 0, int _v = 0, int _w = 0){op = _op, u = _u, v = _v, w = _w;}
}e[M], g[M];
int fa[N], siz[N], c[N];
int find(int x){
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int x, int y){
	int fx = find(x), fy = find(y);
	if(fx == fy) return;
	if(siz[fx] > siz[fy]) swap(fx, fy);
	fa[fx] = fy, siz[fy] += siz[fx];
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	read(n, m, k);
	_rep(i, 1, m) read(g[i].u, g[i].v, g[i].w);
	_rep(i, 1, n) fa[i] = i, siz[i] = 1;
	sort(g + 1, g + 1 + m, [](edge x, edge y){return x.w < y.w;});
	int len = m; m = 0;
	_rep(i, 1, len){
		int u = g[i].u, v = g[i].v, w = g[i].w;
		if(find(u) != find(v)){
			e[++m] = g[i];
			merge(u, v);
		}
	}
//	debug("m:%d\n",m );
	_rep(i, 1, k){
		read(c[i]);
		_rep(j, 1, n){
			e[++m] = edge(i, i + n, j, 0);
			read(e[m].w);
		}
	}
	sort(e + 1, e + 1 + m, [](edge x, edge y){return x.w < y.w;});
	int tot = (1 << k) - 1;
	ll ans = inf;
	_rep(t, 0, tot){
		_rep(i, 1, n + k) fa[i] = i, siz[i] = 1;
		ll cur = 0;
		_rep(j, 1, k) if(t >> (j - 1) & 1) cur += c[j];
		_rep(i, 1, m){
			if(e[i].op && !(t >> (e[i].op - 1) & 1)) continue;
			int u = e[i].u, v = e[i].v, w = e[i].w;
			if(find(u) != find(v)){
//				if(t == 1) debug("(%d,%d,%d)\n", u, v, w);
				cur += w;
				merge(u, v);
			}
		}
//		if(cur == 8) debug("t:%d\n", t);
		ans = min(ans, cur);
	}
	writeln(ans);
	return 0;
}

