#include<bits/stdc++.h>
#define LL long long 
#define N 10100
#define M 1000005
using namespace std;
int n,m,k;LL ans;
struct Edge{
	int u,v,w;
	Edge(int a=0,int b=0,int c=0)
	:u(a),v(b),w(c){}
} e[M],E[M];
int c[10],id[10][N];
bool can[M];
int fa[N];
int Find(int x){
	return fa[x]^x?fa[x]=Find(fa[x]):x;
}
int cnt;
void DFS(int p,int tot,LL ret){
	if(p>=k){
		if(tot<=n) return;
		for(int i(1);i<=n+k;++i) fa[i]=i;
		for(int i(1),c(0);i<=cnt;++i){
			if(!can[i]) continue;
			int u(E[i].u),v(E[i].v);
			if(Find(u)^Find(v)){
				fa[Find(u)]=Find(v);
				ret+=E[i].w;++c;
			}
		}
		ans=min(ans,ret);
		return;
	}
	for(int i(1);i<=n;++i) can[id[p][i]]=1;
	DFS(p+1,tot+1,ret+c[p]);
	for(int i(1);i<=n;++i) can[id[p][i]]=0;
	DFS(p+1,tot,ret);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i(1);i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	sort(e+1,e+1+m,[](const Edge&a,const Edge&b){
		return a.w<b.w;
	});
	for(int i(1);i<=n;++i) fa[i]=i;
	for(int i(1);cnt<n-1;++i){
		int u(e[i].u),v(e[i].v);
		if(Find(u)^Find(v)){
			fa[Find(u)]=Find(v);
			E[++cnt]=e[i];ans+=e[i].w;
		}
	}
	for(int j(0);j<k;++j){
		scanf("%d",&c[j]);
		for(int i(1),x;i<=n;++i){
			scanf("%d",&x);
			E[++cnt]=Edge(n+1+j,i,x);
		}
	}
	sort(E+1,E+1+cnt,[](const Edge&a,const Edge&b){
		return a.w<b.w;
	});
	for(int i(1);i<=cnt;++i){
		if(E[i].u>n) id[E[i].u-n-1][E[i].v]=i;
		else can[i]=1;
	}
	DFS(0,n,0);
	printf("%lld\n",ans);
	return 0;
}
