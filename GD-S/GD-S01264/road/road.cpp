#include<iostream>
#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=1e4+114,maxm=1e6+114;
const long long inF=1e9+114;
int n,m,k;
long long dist[maxn],maydist[maxn];
long long ans,trueans;
long long c[12],a[12][maxn];
struct rec{
	int v,nxt;
	long long w;
}en[maxm*2];
int ecnt,fit[maxn];
void addedge(int u,int v,long long w){
	++ecnt;
	en[ecnt].v=v;
	en[ecnt].w=w;
	en[ecnt].nxt=fit[u];
	fit[u]=ecnt;
}
bool vis[maxn];
int maytree[maxn],orgtree[maxn];
void mintree(){
	for(int i=2;i<=n;i++) vis[i]=false;
	for(int i=2;i<=n;i++) dist[i]=inF;
	for(int i=2;i<=n+k;i++) orgtree[i]=0;
	dist[1]=0;
	orgtree[1]=0;
	vis[1]=true;
	int u=1,lw=inF;
	for(int i=1;i<n;i++){
		for(int j=fit[u];j;j=en[j].nxt){
			int v=en[j].v;
			if(vis[v]) continue;
			if(dist[v]>en[j].w){
				dist[v]=en[j].w;
				orgtree[v]=u;
			}
		}
		lw=inF;
		for(int j=1;j<=n;j++) if(!vis[j]){
			if(dist[j]<lw){
				lw=dist[j];
				u=j;
			}
		}
		ans+=dist[u];
		vis[u]=true;
	}
	return ;
}
void buildnew(int p){
	if(maytree[p]==0) return ;
	buildnew(maytree[p]);
	maytree[maytree[p]]=p;
	maydist[maytree[p]]=maydist[p];
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u=0,v=0;i<=m;i++){
		long long w=0;
		scanf("%d%d%lld",&u,&v,&w);
		addedge(u,v,w);
		addedge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++) scanf("%lld",&a[i][j]);
	}
	mintree();
	trueans=ans;
	for(int i=(1<<k)-1;i>=1;i--){
		for(int j=1;j<=n+k;j++) maydist[j]=dist[j];
		for(int j=1;j<=n+k;j++) maytree[j]=orgtree[j];
		long long mayans=ans;
		for(int j=1;j<=k;j++) if((1<<(j-1))&i){
			mayans+=c[j];
			int u=0,lw=inF;
			for(int hhh=1;hhh<=n;hhh++){
				if(a[j][hhh]<lw){
					lw=a[j][hhh];
					u=hhh;
				}
			}
			buildnew(u);
			maytree[u]=n+j;
			maydist[u]=lw;
			maytree[n+j]=0;
			maydist[n+j]=0;
			mayans+=lw;
			for(int hhh=1;hhh<=n;hhh++){
				if(hhh!=u){
					if(maydist[hhh]>a[j][hhh]){
						mayans-=(maydist[hhh]-a[j][hhh]);
						maydist[hhh]=a[j][hhh];
						maytree[hhh]=n+j;
					}
				}
			}
		}
		trueans=min(trueans,mayans);
	}
	printf("%lld",trueans);
	return 0;
}
