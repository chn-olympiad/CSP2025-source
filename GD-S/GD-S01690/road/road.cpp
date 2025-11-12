#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
const LL INF=1e14+5;
const int N=1e4+5,M=1e6+5,rINF=1e9+5;
LL ans=INF;
bool vis[N];
int n,m,k,idx,head[N];
int c[N],a[12][N];
int U[M],V[M],W[M];
int dis[N];
struct Edge{int v,next,w;}e[M<<1],E[M<<1];
void link(int x,int y,int z){
	e[++idx].v=y;
	e[idx].next=head[x];
	e[idx].w=z;
	head[x]=idx;
}
priority_queue<PII,vector<PII>,greater<PII> >q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		link(u,v,w);link(v,u,w);
		U[i]=u,V[i]=v,W[i]=w;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	for(int S=0;S<(1<<k);S++){
		LL res=0;
		for(int i=1;i<=n+k;i++)dis[i]=rINF,vis[i]=0;
		dis[1]=-1;q.push(make_pair(-1,1));
		for(int id=1;id<=k;id++)
			if((S>>(id-1))&1)res+=c[id];
		while(!q.empty()){
			PII tp=q.top();
			q.pop();
			int u=tp.second;
			if(tp.first>dis[u]||vis[u])continue;
			dis[u]=-1;vis[u]=1;
			if(tp.first!=-1)res+=tp.first;
			if(u<=n){
				for(int i=head[u];i;i=e[i].next){
					int v=e[i].v,w=e[i].w;
					if(vis[v])continue;
					if(w<dis[v])q.push(make_pair(w,v)),dis[v]=w;
				}
				for(int j=1;j<=k;j++){
					if(dis[j+n]<=a[j][u])continue;
					if(vis[j+n])continue;
					if((S>>(j-1))&1)
						q.push(make_pair(a[j][u],j+n));
				}
			}
			else {
				for(int v=1;v<=n;v++)
					if(dis[v]>a[u-n][v]&&!vis[v])
						q.push(make_pair(a[u-n][v],v)),dis[v]=a[u-n][v];
			}
		}
		ans=min(ans,res);
	}
	printf("%lld",ans);
	return 0;
}
