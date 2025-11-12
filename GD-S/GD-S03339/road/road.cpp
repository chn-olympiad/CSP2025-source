#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long ;
template<typename T>
void rd(T &s){
	s=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		s=(s<<1)+(s<<3)+(c-48);
		c=getchar();
	}
}
const int N=1e4+20,M=1e6+20;
int n,m,k;
struct Edge{
	int u,v;
	ll w;
	bool operator<(const Edge &oth)const{
		return w<oth.w;
	}
}e[M+N];
ll a[15][M],c[15],ans;
int par[N],siz[N];
int Find(int x){
	return x==par[x]?x:par[x]=Find(par[x]);
}
void merge(int x,int y){
	if(siz[x]>siz[y]) swap(x,y);
	siz[y]+=siz[x];
	par[x]=y;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	rd(n),rd(m),rd(k);
	for(int i=1;i<=m;i++){
		rd(e[i].u),rd(e[i].v),rd(e[i].w);
	}
	for(int i=1;i<=k;i++){
		rd(c[i]);
		for(int j=1;j<=n;j++){
			rd(a[i][j]);
			e[++m].u=i+n;
			e[m].v=j;
			e[m].w=a[i][j];
		}
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=n+k;i++) par[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v;
		ll w=e[i].w;
		int fu=Find(u),fv=Find(v);
		if(fu==fv) continue;
		ans+=w;
		merge(fu,fv);
	}
	printf("%lld",ans);
	return 0;
}
