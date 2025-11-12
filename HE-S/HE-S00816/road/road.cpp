#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template<typename T>inline void read(T &x) {
    x=0;int f=1;char ch=getchar();
    while (ch <'0' || ch >'9') {
        if (ch=='-') f=-1;
        ch=getchar();
    }
    while (ch>='0'&&ch <='9') {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    x*=f;
}
const int maxn = 1e4+5;
const int maxm = 1e6+5;
int n,m,k;
struct edge{
	int u,v;ll w;
	bool operator < (const edge &y) const {
		return w < y.w;
	} 
}e[maxm<<1];
//,e1[12][maxn]
//bool f[maxm];
//edge ew[1<<10][maxn*2];
int tot = 0;
int father[maxn<<1];
inline int find(int x) {
	int t = x;
	while (x != father[x]) x = father[x];
	int w;
	while (t != father[t]) w = father[t],father[t] = x,t = w;
	return x;
}
ll val[maxn];
ll ans = 0;
inline void kruskal() {
	for (int i = 1; i <= n+k; i++) father[i] = i;
//	int t = n;
//	for (int j = 1; j <= k; j++) if (t>>(j-1)&1) father[j+n] = j+n,++t;
	int cnt = 0;
//	if (__builtin_expect(t==0,0)) {
		sort(e+1,e+tot+1);
		for (int i = 1; i <= tot; i++) {
			int p = find(e[i].u),q = find(e[i].v);
			if (p == q) continue;
			father[p] = q;
			++cnt;
			ans += e[i].w;
//			f[i] = true; 
			if (cnt == n+k-1) break;
		}
//		for (int i = 1; i <= m; i++) if (f[i]) ew[0][++tot] = {e[i].u,e[i].v,e[i].w};
//		return;
//	}
//	for (int i )
}
int main () {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    read(n),read(m),read(k);
    for (int i = 1; i <= m; i++) {
    	read(e[i].u),read(e[i].v),read(e[i].w);
	}
	tot = m;
	for (int i = 1; i <= k; i++) {
		read(val[i]);
		for (int j = 1; j <= n; j++) {
//			e1[i][j].u = n+i,e1[i][j].v = j,read(e1[i][j].w);
			e[++tot].u = n+i,e[tot].v = j,read(e[tot].w);
		}
	}
	kruskal();
//	for (int i = 1; i <= tot; i++) cerr << e[i].w << '\n';
	printf("%lld",ans);
    return 0;
}
