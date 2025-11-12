#include<bits/stdc++.h>
using namespace std;
int sn,n,k,m,sm;
int f[20001];
int findfa(int x){
	if(f[x]==x)return x;
	f[x]=findfa(f[x]);
	return f[x];
}
struct edge{
	int u,v;
	long long w;
}e[2000001];
bool cmp(edge a,edge b){return a.w<b.w;}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int uu,vv;
		long long ww;
		scanf("%d%d%lld",&uu,&vv,&ww);
		++sm;
		e[sm].u=uu,e[sm].v=vv,e[sm].w=ww;
	}
	for(int i=1;i<=k;i++){
		long long x;
		scanf("%lld",&x);
		for(int j=1;j<=n;j++){
			long long ww;
			scanf("%lld",&ww);
			++sm;
			e[sm].u=n+i,e[sm].v=j,e[sm].w=ww;
		}
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	sort(e+1,e+sm+1,cmp);
	long long ans=0;
	for(int i=1;i<=sm;i++){
		int S=findfa(e[i].u),T=findfa(e[i].v);
		if(S==T)continue;
		f[S]=T;
		ans+=e[i].w;
	}
	printf("%lld",ans);
	return 0;
}
