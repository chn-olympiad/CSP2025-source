#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
	int u,v,w;
	edge(int x=0,int y=0,int z=0):u(x),v(y),w(z){}
}e[N*2],t[20005];
bool cmp(edge x,edge y){return x.w<y.w;}
int ce,c[N],r[11][10005],ct,fa[N];
int fd(int x){
	if(fa[x]==x)return x;
	return fa[x]=fd(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n+k;++i)fa[i]=i;
	for(int i=1,u,v,w;i<=m;++i){
		scanf("%d%d%d",&u,&v,&w);
		e[++ce]=edge(u,v,w);
	}
	for(int i=1,ci,a;i<=k;++i){
		scanf("%d",&ci);
		c[i]=ci;
		for(int j=1;j<=n;++j){
			scanf("%d",&r[i][j]);
		}
	}
	sort(e+1,e+ce+1,cmp);
	long long cost=0;
	for(int i=1,en=1;en<n&&i<=ce;++i){
		int fx=fd(e[i].u),fy=fd(e[i].v);
		if(fx==fy)continue;
		fa[fx]=fy;
		en++;
		t[++ct]=e[i];
		cost+=e[i].w;
	}
	int ctt=ct,nd=1;
	edge tt[20005],at[20005];
	for(int i=1;i<=k;++i){
		long long cst=0;
		int cat=0;
		for(int i=0;i<=n+k;++i)fa[i]=i;
		for(int i=1;i<=ct;++i)tt[i]=t[i];
		for(int j=1;j<=n;++j)tt[++ctt]=edge(n+i,j,r[i][j]);
		sort(tt+1,tt+ctt+1,cmp);
		for(int i=1,en=1;en<n+nd&&i<=ctt;++i){
			int fx=fd(tt[i].u),fy=fd(tt[i].v);
			if(fx==fy)continue;
			fa[fx]=fy;
			en++;
			at[++cat]=tt[i];
			cst+=tt[i].w;
		}
		if(cst+c[i]<cost){
			cost=cst;
			ct=ctt;
			nd++;
			for(int i=1;i<=cat;++i)t[i]=at[i];
		}
	}
	printf("%lld",cost);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
