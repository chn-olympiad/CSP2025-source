#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;
using lint = long long;
const int maxn = 1e4 + 514;
const int maxm = 1e6 + 9;
const lint inf = 0x7f7f7f7f7f7f7f7f;

char buf[1<<20], *p1=buf, *p2=buf;
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin))==p1?EOF:*p1++)
lint read(){
	lint rs = 0, c = 0;
	while ('9' < c || c < '0'){
		c = getc();
	} while (!('9' < c || c < '0')){
		rs = rs*10 + (c^48), c = getc();
	} return rs;
}

#define rep(i, j, k) for ((i) = (j); (i) <= (k); ++(i))

int n, m, kk;

int hed[maxn];
int en = 1;
int to[maxm<<1];
int nx[maxm<<1];
lint ww[maxm<<1];

int cs[12];
lint va[12][maxn];

void link(int u, int v, lint w){
	to[++en] = v, ww[en] = w, nx[en] = hed[u], hed[u] = en;
}

namespace k0case{
	int fth[maxn];
	int siz[maxn];
	
	int find(int x){
		return fth[x] ? fth[x] = find(fth[x]) : x;
	}
	
	bool merge(int a, int b){
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (siz[a] > siz[b]) swap(a, b);
		fth[a] = b, siz[b] += siz[a];
		return 1; 
	}
	
	struct edg{
		int u;
		int v;
		lint w;
	} e[maxm];
	
	void solve(){
		int i, j;
		
		rep (i, 1, n){
			siz[i] = 1;
		}
		rep (i, 1, m){
			int u = read(), v = read();
			lint w = read();
			e[i] = {u, v, w};
		}
		
		sort(e + 1, e + m + 1, [](edg a, edg b){
			return a.w < b.w;
		});
		
		lint ans = 0;
		rep (i, 1, m){
			ans += merge(e[i].u, e[i].v) * e[i].w;
		}
		
		printf("%lld\n", ans);
	}
}

namespace lowkcase{
	int fth[maxn];
	int siz[maxn];
	
	int find(int x){
		return fth[x] ? fth[x] = find(fth[x]) : x;
	}
	
	bool merge(int a, int b){
		a = find(a), b = find(b);
		if (a == b) return 0;
		if (siz[a] > siz[b]) swap(a, b);
		fth[a] = b, siz[b] += siz[a];
		return 1; 
	}
	
	int enn = 0;
	struct edg{
		int u;
		int v;
		lint w;
	} e[maxm];
	
	int nen;
	edg ts[maxm<<1];
	
	lint kruskal(int s){
		int i, j;
		lint res = 0;
		
		rep (i, 1, enn){
			ts[i] = e[i];
		}
		nen = enn;
		
//		cerr << s << ", ";
		
		for (i = 1; s; ++i){
			if (s&1){
				res += cs[i];
				rep(j, 1, n){
					ts[++nen] = {n+i, j, va[i][j]};
				}
			}
			s >>= 1;
		}
		
		rep (i, 1, n+kk){
			siz[i] = 1, fth[i] = 0;
		}
		
		sort(ts + 1, ts + nen + 1, [](edg a, edg b){
			return a.w < b.w;
		});
		
		lint ans = 0;
		rep (i, 1, nen){
			bool ok = merge(ts[i].u, ts[i].v);
//			if (ok) cerr << ts[i].u << ", " << ts[i].v << '\n';
			res += ok * ts[i].w;
		}
		
//		cerr << res << '\n'; 
		
		return res;
	}
	
	int ndn;
	lint prim(int s){
		int i, j;
		
		static lint ato[maxn];
		static bitset<maxn> vsd;
		static int orihed[maxn];
		lint res = 0;
		
		ndn = en;
		rep (i, 0, n+kk){
			orihed[i] = hed[i];
			ato[i] = inf, vsd[i] = 0;
		}
		
		for (i = 1; s; ++i){
			if (s&1){
				res += cs[i];
				rep(j, 1, n){
					link(n+i, j, va[i][j]);
					link(j, n+i, va[i][j]);
				}
			}
			s >>= 1;
		}
		
		ato[1] = 0;
		while (1){
			bool flag = 1;
			int nxt = 0;
			rep (i, 1, n+kk){
				if (vsd[i]) continue;
				flag = 0;
				if (ato[i] < ato[nxt]){
					nxt = i;
				}
			}
			
			res += ato[nxt], vsd[nxt] = 1;
			
			if (flag) break;
			for (i = hed[nxt]; i; i = nx[i]){
				ato[to[i]] = min(ato[to[i]], ww[i]);
			}
		}
		
		rep (i, 0, n+kk){
			hed[i] = orihed[i];
		}
		en = ndn;
		
		return res;
	}
	
	lint dfs(int nw, int p){
		if (p == kk){
//			lint res = prim(nw);
			lint res = kruskal(nw);
//		cerr << "KOishi\n";
			return res;
		}
		lint res = inf;
		res = min(res, dfs((nw<<1)|1, p+1));
		res = min(res, dfs(nw<<1, p+1));
		return res;
	}
	
	void solve(){
		int i, j, k;
		
		rep (i, 1, n){
			siz[i] = 1;
		}
		rep (i, 1, m){
			int u = read(), v = read();
			lint ww = read();
			link(u, v, ww), link(v, u, ww);
			e[++enn] = {u ,v, ww};
		}
		
		rep (i, 1, kk){
			cs[i] = read();
			rep (j, 1, n){
				va[i][j] = read();
			}
		}
		
		printf("%lld\n", dfs(0, 0));
	}
}

int enn = 0;
struct edg{
	int u;
	int v;
	lint w;
} e[maxn];

int main(){
	int i, j;

	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);


	n = read(), m = read(), kk = read();
	
	if (kk <= 0){
		k0case::solve();
	}
	else{
		lowkcase::solve();
	}
	
	return 0;
}
