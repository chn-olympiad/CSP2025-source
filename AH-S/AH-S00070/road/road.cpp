#include<bits/stdc++.h>
using namespace std;
int n,m,k,fa[10005],sum;
struct edge{
	int from,to,w;
}e[3000005];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
bool check(){
	int f=find(1);
	for(int i=2;i<=n;i++){
		if(find(i)!=f)return false;
	}
	return true;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
		e[i+1]={v,u,w};
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	m=m*2;
	for(int i=1;i<=k;i++){
		int v,w;
		scanf("%d",&v);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			e[++m]={i,j,w+v};
			e[++m]={j,i,w+v};
		}
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(check()){
			printf("%d",sum);
			break;
		}else if(find(e[i].from)==find(e[i].to))continue;
		sum+=e[i].w;
		fa[find(e[i].to)]=find(e[i].from);
	}
}
