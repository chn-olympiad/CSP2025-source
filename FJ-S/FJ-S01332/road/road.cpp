#include<iostream>
#include<stdio.h>
#include<algorithm>
#define int long long
using namespace std;
const int N=1e4+5,M=1e6+5;
int fa[N];
struct edge{
	int u,v,w;
}e[M],h[M*2],g[M];int cnt,mcnt;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int n,m,k,city,ans=1e18;
int open[11],cost[11][N];bool use[11];
int fnd(int x){
	if(x==fa[x])return x;
	return fa[x]=fnd(fa[x]);
}
void ksl(int mon){
	mcnt=0;
	for(int i=1;i<=m;i++)h[++mcnt]=e[i];
	for(int i=1;i<=cnt;i++)h[++mcnt]=g[i];
	for(int i=1;i<=city;i++)fa[i]=i;
	sort(h+1,h+1+mcnt,cmp);
	for(int i=1;i<=mcnt;i++){
		if(fnd(h[i].u)!=fnd(h[i].v)){
			mon+=h[i].w;
			fa[fnd(h[i].u)]=fnd(h[i].v);
		}
	}
	ans=min(ans,mon);
}
void dfs(int x,int basic){
	if(x==k+1){
		ksl(basic);
		return;
	}
	city++;
	for(int i=1;i<=n;i++){
		g[++cnt].u=city;
		g[cnt].v=i;
		g[cnt].w=cost[x][i];
	}
	dfs(x+1,basic+open[x]);
	cnt-=n,city--;
	dfs(x+1,basic);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	city=n;
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&open[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&cost[i][j]);
		}
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
