#include<bits/stdc++.h>
using namespace std;
const int N=1e4+15,M=1.5e6+5,K=15;
typedef long long ll;
int n,m,k,a[K],cnt;
ll sum;
struct edge{int u,v,w;}e[M];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
ll kruskal(){
	sort(e+1,e+cnt+1,[](edge a,edge b){return a.w<b.w;});
	iota(fa+1,fa+1+n+k,1);
	ll res=0;
	for(int i=1;i<=cnt;i++){
		if(find(e[i].u)!=find(e[i].v)){
			fa[find(e[i].u)]=find(e[i].v);
			res+=e[i].w;
		}
	}
	return res;
}
int read(){
	int x=0;char c=getchar();
	while(c<'0'||c>'9')  c=getchar();
	while(c>='0'&&c<='9')  x=x*10+c-'0',c=getchar();
	return x;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=m;i++){
		e[i]={read(),read(),read()};
	}
	cnt=m;
	ll ans=kruskal();
	for(int i=1;i<=k;i++){
		sum+=read();
		for(int j=1;j<=n;j++){
			e[++cnt]={i+n,j,read()};
		}
		ans=min(ans,sum+kruskal());
	}
	printf("%lld",ans);
	return 0;
}
//为什么这么难 
