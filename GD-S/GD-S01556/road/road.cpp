#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5, M=1e6+5;
const ll inf = 1e18;
int n, m, k, fat[N+15], a[15][N], c[15];
ll ans, res;
struct Edg{
	int u, v, w;
	bool operator<(Edg b)const{
		return w < b.w;
	}
}e[M], e1[N], e2[M+N*10];
inline void chkmin(ll &x, ll y){
	x = y<x?y:x;
}
int find(int x){
	return fat[x]==x ? x:fat[x]=find(fat[x]);
}
inline void kruscal(int E, int siz, Edg e[], bool flag){
	sort(e+1, e+1+E);
	for(int i=1; i<=n+k; ++i) fat[i] = i;
	int cho = 0;
	for(int i=1; i<=E; ++i)
		if(find(e[i].u) != find(e[i].v)){
			fat[find(e[i].u)] = find(e[i].v);
			if(!flag) res+=e[i].w, ++cho;
			else e1[++cho] = e[i];
			if(cho == siz-1) return;
		}
}
inline void solve(int st){
	for(int i=1; i<n; ++i) e2[i] = e1[i];
	int ppc=0, cnt=n-1;
	res = 0;
	for(int i=1; i<=k; ++i)
		if((st>>i-1) & 1){
			++ppc; res+=c[i];
			for(int j=1; j<=n; ++j)
				e2[++cnt] = {n+i,j,a[i][j]};
		}
	kruscal(cnt, ppc+n, e2, 0);
	chkmin(ans, res);
//	printf("%d %lld\n", st, res);
}
inline void read(int &x){
	x = 0;
	char ch;
	do{
		ch = getchar();
	}while(ch<48 || ch>57);
	while(ch>=48 && ch<=57){
		x = (x<<3)+(x<<1)+ch-48;
		ch = getchar();
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ans = inf;
	read(n); read(m); read(k);
	for(int i=1; i<=m; ++i){
		read(e[i].u); read(e[i].v); read(e[i].w);
	}
	bool flag = true;
	for(int i=1; i<=k; ++i){
		read(c[i]);
		flag &= (c[i]==0);
		for(int j=1; j<=n; ++j){
			read(a[i][j]);
			flag &= (a[i][j]==0);
		}
	}

	kruscal(m, n, e, 1);
//	for(int i=1; i<n; ++i) printf("%d %d %d\n", e1[i].u, e1[i].v, e1[i].w);
	if(flag) solve((1<<k)-1);
	else{
		for(int st=(1<<k)-1; st>=0; --st)
			solve(st);
	}
	printf("%lld\n", ans);
	return 0;
}
