#include<bits/stdc++.h>
using namespace std;
int n,m,k,u,v,fa[10005];
long long c[10005],a[10005][10005],w;
long long ans=0; 
struct Edg{
	int u,v;
	long long wei;
}edg[3000006];
bool cmp(Edg a,Edg b){
	return a.wei<b.wei;
}
int head[10005],cnt=0;
void adeg(int u,int v,long long w){
	edg[++cnt].wei=w;
	edg[cnt].u=u;
	edg[cnt].v=v;
}
int find(int x){
	if(x==fa[x])return x;
	return fa[x]=find(fa[x]);
}
void kruskal(){
	int ecnt=0;
	sort(edg+1,edg+m+1,cmp);
	for(int i=1;i<=m;++i){
		int u=edg[i].u;
		int v=edg[i].v;
		if(u<=k||v<=k||find(u)==find(v))continue;
		ans+=edg[i].wei;
		fa[find(u)]=find(v);
		++ecnt;
		if(ecnt==n-k-1)return;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1;i<=m;++i){
		scanf("%d %d %lld",&u,&v,&w);
		adeg(u,v,w);
		adeg(v,u,w);
	}
	for(int i=1;i<=k;++i){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;++j)scanf("%lld",&a[i][j]);
	}
	kruskal(); 
	printf("%lld",ans);
	return 0;
}
