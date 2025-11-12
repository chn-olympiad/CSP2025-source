#include<bits/stdc++.h>
using namespace std;
const int N=1e4+20,M=1.1e6+10;
int n,m,k,head[N],tot,u,v,ww,c[15],vis,dis[N],minn,ans,last;
bool visit[N];
struct Edge{
	int next,to,w;
}edge[2*M];
void add(int u,int v,int ww){
	edge[++tot].next=head[u];
	edge[tot].to=v;
	edge[tot].w=ww;
	head[u]=tot;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>ww;
		add(u,v,ww);
		add(v,u,ww);
		dis[i]=0x7f;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>ww;
			add(n+i,j,ww+c[i]);
			add(j,n+i,ww+c[i]);
		}
		dis[n+i]=0x7f;
	}
	vis=1;visit[1]=1;dis[1]=0;last=1;
	for(int i=head[1];i;i=edge[i].next){
		v=edge[i].to;
		dis[v]=edge[i].w;
	}
	while(vis!=n){
		minn=0x7f;
		for(int i=1;i<=n+k;i++){
			if(visit[i])continue;
			if(dis[i]==0)continue;
			if(dis[i]<minn)u=i,minn=dis[i];
		}
		for(int i=head[last];i;i=edge[i].next){
			if(edge[i].to==u)ans+=edge[i].w;
		}
		visit[u]=1;
		if(u<=n)vis++;
		else{
			for(int i=head[u];i;i=edge[i].next){
				edge[i].w-=c[u-n];
			}
		}
		for(int i=head[u];i;i=edge[i].next){
			v=edge[i].to;
			if(visit[v])continue;
			dis[v]=min(dis[v],dis[u]+edge[i].w);
		}
		last=u;
	}
	cout<<ans;
	return 0;
}
