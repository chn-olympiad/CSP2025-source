#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+20;
const int maxm=1e6+20;
typedef long long ll;
int n,m,k;
struct DSU{
	int fa[maxn],sz[maxn];
	void prepare(){for(int i=1;i<=n+k;i++) fa[i]=i,sz[i]=1;}
	int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
	bool merge(int x,int y){
		x=find(x);y=find(y);
		if(x==y) return 0;
		if(sz[x]<sz[y]) swap(x,y);
		fa[y]=x;sz[x]+=sz[y];return 1;
	}
}dsu;
struct edge{
	int u,v;ll w;
}ed[maxm+11*maxn],ed2[maxm+11*maxn];
bool vis[maxm+11*maxn];
ll c[11],a[11][maxn];
int pos[11];
long long kruskal(){
	dsu.prepare();long long s=0;
	for(int i=1;i<=m;i++) ed2[i]=ed[i];
	sort(ed2+1,ed2+m+1,[](edge x,edge y){return x.w<y.w;});
	for(int i=1;i<=m;i++){
		int u=ed2[i].u,v=ed2[i].v;vis[i]=0;
		if(dsu.merge(u,v)) vis[i]=1,s+=ed2[i].w;
	}return s;
}
long long kruskal2(){
	dsu.prepare();long long s=0;
	sort(ed+1,ed+m+1,[](edge x,edge y){return x.w<y.w;});
	for(int i=1;i<=m;i++){
		int u=ed[i].u,v=ed[i].v;vis[i]=0;
		if(dsu.merge(u,v)) vis[i]=1,s+=ed[i].w;
	}return s;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&ed[i].u,&ed[i].v,&ed[i].w);
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}int k2=0;
	for(int i=1;i<=k;i++){
		if(c[i]!=0){pos[++k2]=i;continue;}
		int tp=0;
		for(int j=1;j<=n;j++) if(a[i][j]==0) tp=j;
		if(!tp){pos[++k2]=i;continue;}
		for(int j=1;j<=n;j++) if(j!=tp) ed[++m]={tp,j,a[i][j]};
	}k=k2;
	if((1ll<<k)*m*__lg(m)>1.6e9){
		long long preans=kruskal2();
		int m2=0;
		for(int i=1;i<=m;i++) if(vis[i]) ed[++m2]=ed[i];
		m=m2;
		for(int s=0;s<(1<<k);s++){
			m2=m;long long ans=0;
			for(int j=1;j<=k;j++) if((s>>(j-1))&1){
				ans+=c[j];
				for(int l=1;l<=n;l++) ed[++m]={n+j,l,a[j][l]};
			}ans+=kruskal2();preans=min(preans,ans);
			m=m2;
		}printf("%lld\n",preans);
	}else{
		ll preans=1e18;
		for(int s=0;s<(1<<k);s++){
			int m2=m;ll ans=0;
			for(int j=1;j<=k;j++) if((s>>(j-1))&1){
				int u=pos[j];ans+=c[u];
				for(int l=1;l<=n;l++) ed[++m]={n+u,l,a[u][l]};
			}ans+=kruskal();preans=min(preans,ans);
			m=m2;
		}printf("%lld\n",preans);
	}
	return 0;
}
