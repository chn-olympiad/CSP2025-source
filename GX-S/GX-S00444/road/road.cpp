#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k;
struct edge{
	int u,v,d;
}e[1000005];
int fa[10005];
int dis[11][10005];
int findf(int x){
	if(fa[x]==x)return x;
	return findf(fa[x]);
}
bool cmp(edge xx,edge yy){
	return xx.d<yy.d;
}
void solve1(){	//only k==0
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
	}
	sort(e,e+m,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		int u=e[i].u,v=e[i].v;
		int fu=findf(u),fv=findf(v);
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=e[i].d;
	}
	printf("%d",ans);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	scanf("%d%d%d",&n,&m,&k);
	if(!k){
		solve1();
		return 0;
	}
	
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<=n;j++){
			scanf("%d",&dis[i][j]);
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			int u=e[i].u,v=e[i].v;
			e[i].d=min(e[i].d,dis[j][u]+dis[j][v]);
		}
	}
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(e,e+m,cmp);
	int ans=0;
	for(int i=0;i<m;i++){
		int u=e[i].u,v=e[i].v;
		int fu=findf(u),fv=findf(v);
		//cout<<fu<<endl;
		if(fu==fv)continue;
		fa[fu]=fv;
		ans+=e[i].d;
	}
	printf("%d",ans);
	return 0;
}
