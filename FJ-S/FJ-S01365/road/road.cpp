#include<stdio.h>
#include<algorithm>
int n,m,k,s,i,x,y;
int f[10001];
int find(int x){
	while(x!=f[x])x=f[x]=f[f[x]];
	return x;
}
struct edge{
	int u,v,w;
}e[1000000];
inline bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(i=0;i^m;++i)scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	std::sort(e,e+m,cmp);
	for(i=1;i<=n;++i)f[i]=i;
	for(i=0;i^m;++i){
		x=find(e[i].u),y=find(e[i].v);
		if(x!=y)f[x]=y,s+=e[i].w;
	}
	printf("%d",s);
	return 0;
}
