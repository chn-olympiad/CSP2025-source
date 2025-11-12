#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=1e6+5,N=1e5+25;
struct Edge{int u,v;ll w;} e[M];
bool operator<(Edge x,Edge y){return x.w<y.w;}
int f[N],c[M],cs[N];
int Find(int x){return x==f[x]?x:(f[x]=Find(f[x]));}
void Merge(int x,int y){
	x=Find(x),y=Find(y);
	if(x^y) f[x]=y;
}
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int u,v,w,tot=0;ll sum,ans=1e18+1;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) f[i]=i,cs[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		e[i]={u,v,w};
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++){
		u=Find(e[i].u),v=Find(e[i].v);
		if(u!=v){Merge(u,v);e[++tot]=e[i];}
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&w);
			e[++tot]={i+n,j,w};
		}
	}
	m=tot;sort(e+1,e+m+1);
	for(int i=0;i<(1<<k);i++){
		sum=0;
		for(int j=1;j<=k;j++){
			if((i>>j-1)&1) sum+=c[j],cs[j+n]=1;
			else cs[j+n]=0;
		}
		for(int j=1;j<=n+k;j++) f[j]=j;
		for(int j=1;j<=m;j++){
			u=Find(e[j].u),v=Find(e[j].v);
			if(u==v||!cs[u]||!cs[v]) continue;
			f[u]=v;sum+=e[j].w;
		}
		// printf("%d %lld \n",i,sum);
		ans=min(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}