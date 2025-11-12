#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
const int M=1e5+5;
int n,m,k;
int w[N];
typedef struct Edge{
	int to,next,dis;
}Edge;
Edge g[N];
int head[N];
int cnt;
int dis[M],pre[M];
bool vis[M];
void addEdge(int u,int v,int dis){
	g[++cnt].to=v;
	g[cnt].next=head[u];
	g[cnt].dis=dis;
	head[u]=cnt;
}
void D(int s){
	dis[s]=0;
	for(int i=1;i<=n;i++){
		int loc=0,mindis=INT_MAX;
		for(int j=1;j<=n;j++){
			if(!vis[j]&&mindis>dis[j]){
				loc=j;
				mindis=dis[j];
			}
		}
		if(loc==0) break;
		vis[loc]=true;
		int next=head[loc];
		for(;next!=0;next=g[next].next){
			int v=g[next].to;
			int d=g[next].dis;
			if(dis[v]>=dis[loc]+d){
				dis[v]=dis[loc]+d;
				pre[v]=d;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			D(i);
		}
	}
	return;
}
int main(){
      freopen("road.in","r",stdin);
      freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,d;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>d;
		addEdge(u,v,d);
		addEdge(v,u,d);
	}
	for(int i=0;i<=n;i++){
		cin>>w[i];
	}
	memset(dis,0x3f,sizeof(dis));
	D(1);
	int ans=0;
	sort(pre+1,pre+n+1);
	for(int i=1;i<=n-k;i++){
		ans+=pre[i];
	}
	cout<<ans<<endl;
        return 0;
} 
