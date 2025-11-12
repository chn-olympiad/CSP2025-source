#include <bits/stdc++.h>
#define f(i,a,b) for ( int i = a ; i <= b ; i++ )
#define rt return
using namespace std;
typedef long long LL;
const int maxn=1e4+2,maxm=1e6+2;
int n,m,k,town[12][maxn];
int fa[maxn];
struct edge {
	int u,v,w;
} road[maxm];

inline void in() {
	scanf("%d%d%d", &n, &m, &k);
	f(i,1,m) scanf("%d%d%d", road[i].u, road[i].v, road[i].w);
	f(i,1,k) f(j,1,n) scanf("%d", town[i][j]);
	f(i,1,n) fa[i] = i;
	rt;
}
int find(int t) {
	rt fa[t] == t ? t : fa[t] = find(t);
}
inline bool cmp(edge a, edge b) {
	rt a.w < b.w;
}
inline LL had() {
	LL ans=0;
	int f1,f2;
	sort(road+1, road+m+1, cmp);
	f(i,1,m) {
		f1 = find(road[i].u);
		f2 = find(road[i].v);
		if ( f1 != f2 ) {
			ans += road[i].w;
			fa[f1] = f2;
		}
	}
	rt ans;
}
inline void doit() {
	printf("%lld", had());
	rt;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	in();
	doit();
	rt 0;
}
