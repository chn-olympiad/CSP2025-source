#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define LOCAL//
namespace IO{
	const int len = 1 << 20;
#ifdef LOCAL
	inline char GC(){return getchar();}
#else
	static char ibuf[len], *iS = ibuf, *iT = ibuf;
	inline char GC(){return iS==iT&&(iT=(iS=ibuf)+fread(ibuf,1,len,stdin),iS==iT)?EOF:*iS++;}
#endif
	template <typename T>
	inline void read(T &x){
		x = 0; bool f = false; char c = GC();
		while(c < '0' || c > '9'){
			f |= (c == '-'); c = GC();
		}
		while(c >= '0' && c <= '9'){
			x = (x << 3) + (x << 1) + (c ^ 48); c = GC();
		}
		if(f) x = ~(x - 1);
	}
}
using IO::read;
const int mxn = 10100, mxm = 1e6+10, mxK = (1 << 10) + 5;
int n, m, k, tot, val[20], a[11][mxn], d[11][mxn], tmp[mxn];
ll ans;
struct Edge{
	int u, v, w;
} b[mxm], c[mxm];
int fa[mxn];
int fnd(int x){return x==fa[x]?x:(fa[x]=fnd(fa[x]));}
int ct[mxK], id[mxK][mxn];
bool mrg(int u, int v){
	u = fnd(u); v = fnd(v);
	if(u != v){
		fa[v] = u;
		return true;
	}
	return false;
}
void solve(){
	tot = 0; ans = (ll)1e18+10;
	int i, i0, i1, j, p, u, v;
	ll x;
	read(n); read(m); read(k);
	for(i = 1; i <= m; i++){
		read(b[i].u); read(b[i].v); read(b[i].w);
	}
	for(i = 1; i <= k; i++){
		read(val[i]);
		for(j = 1; j <= n; j++){
			read(a[i][j]);
			tmp[j] = a[i][j];
			d[i][j] = j;
			c[++tot] = {n + i, j, a[i][j]};
		}
		sort(d[i] + 1, d[i] + n + 1, [&](const int x, const int y){ return tmp[x] < tmp[y]; });
	}
	sort(b + 1, b + m + 1, [&](const Edge i, const Edge j){ return i.w < j.w; });
	for(i = 1; i <= n; i++) fa[i] = i;
	for(i = 1; i <= m; i++){
		if(mrg(b[i].u, b[i].v)){
			c[++tot] = b[i];
		}
	}
	for(i = 0; i < 1 << k; i++){
		ct[i] = 0;
		x = 0;
		for(j = 1; j <= n + k; j++) fa[j] = j;
		if(i == 0){
			for(j = n * k + 1; j <= tot; j++){
				if(mrg(c[j].u, c[j].v)){
					x += c[j].w;
					id[i][++ct[i]] = j;
				}
			}
		}else{
			i1 = __builtin_ctz(i); i0 = i ^ 1 << i1; i1++;
			for(j = 1, p = 1; j <= ct[i0] || p <= n; 1){
				u = (j <= ct[i0] ? id[i0][j] : 0);
				v = (p <= n ? (i1 - 1) * n + d[i1][p] : 0);
				if(u > 0 && (v == 0 || c[u].w <= c[v].w)){
					if(mrg(c[u].u, c[u].v)){
						x += c[u].w;
						id[i][++ct[i]] = u;
					}
					j++;
				}else{
					if(mrg(c[v].u, c[v].v)){
						x += c[v].w;
						id[i][++ct[i]] = v;
					}
					p++;
				}
			}
		}
		for(j = 1; j <= k; j++){
			if(i >> j - 1 & 1){
				x += val[j];
			}
		}
//		printf("x %d %lld\n", i, x);
		ans = min(ans, x);
	}
	printf("%lld", ans);
}
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int t = 1;
	while(t--) solve();
	return 0;
}
