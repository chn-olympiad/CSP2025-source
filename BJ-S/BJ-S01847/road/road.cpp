#include<bits/stdc++.h>
using namespace std;
const int maxm=1e6+10;
const int maxn=1e4+100;
long long ans=0;
//FILE* debug;
struct edge{
	int from,to;
	long long weight;
};
struct edge2{
	int to,next,weight;
};
struct graph{
	int edges;
};
int fa[maxn];
int gf(int x,bool fst){
	//fprintf(debug,"%d %d !%d\n",x,fa[x],fst);
	if (fa[x]==x){
		return x;
	}
	return fa[x]=gf(fa[x],0);
}
void mrg(int x,int y){
	//cerr<<x<<' '<<y<<'\n';
	//cerr<<gf(x)<<'*'<<gf(y)<<'\n';
	fa[gf(x,1)]=gf(y,1);
}
int n,m,k;
edge es[maxm+maxn*11];
bool edgecmp(edge a,edge b){
	return a.weight<b.weight;
}
void kruskal(){
	for (int i=1;i<=n;i++){
		fa[i]=i;
	}
	sort(es+1,es+m+1,edgecmp);
	for (int i=1;i<=m;i++){
		int u=es[i].from;
		int v=es[i].to;
		if (gf(u,1)!=gf(v,1)){
			ans+=es[i].weight;
			mrg(u,v);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//debug=fopen("debug.log","w");
	scanf("%d%d%d",&n,&m,&k);
	
	//int maxw=0;
	for (int i=1;i<=m;i++){
		int u,v;
		long long w;
		scanf("%d%d%lld",&u,&v,&w);
		es[i].from=u;
		es[i].to=v;
		es[i].weight=w;
		//maxw=max(w,maaxw);
	}
	
	//fprintf(debug,"p1o");
	if (k==0){
		kruskal();
		printf("%lld",ans);
		return 0;
	}
	
	for (int i=1;i<=k;i++){
		int sw;
		scanf("%d",&sw);
		for (int j=1;j<=n;j++){
			long long noww;
			scanf("%d",&noww);
			es[++m]={n+i,j,noww};
		}
	}
	n+=k;
	kruskal();
	printf("%lld",ans);
	return 0;
}
/*
 A:5%
 B:15%
 Baoli:20%
 * 1 2
 * 3 4
 * 5 8
 * 9
 * 15 16
 * ab3
6 9 0
2 6 2
2 3 3
3 6 9
3 4 4
3 5 8
4 6 5
4 5 7
1 5 3
1 6 1
 */

