#include<bits/stdc++.h>
using namespace std;
int dis[1010006],vis[1010006];
struct edge{
	int v,w;
};
vector<edge> g;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n+m;i++){
		dis[i]=INT_MAX;
		
	}
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g[a].v=b;
		g[a].w=c;
	}
	int a[100006],b,c;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++){
			cin>>c;
			g[n+i].v=j;
			g[n+i].w=c+a[i];
		}
	}
	vis[1]=1;
	dis[1]=0;
	long long ans=0;
	for(int i=1;i<=n+m;i++){
		if(vis[i]==1){
			continue;
		}
		int minn=INT_MAX,x=0;
		for(int j=1;j<=n+m;j++){
			if(dis[j]<minn){
				minn=dis[i];
				x=i;
			}
		}
		dis[i]=0;
		vis[x]=1;
		ans+=minn;
		if(x>n){
			for(int j=1;j<=n;j++){
				g[x].w-=a[x-n];
			}
		}
		for(int j=1;j<=n;j++){
			if(g[x].v==j){
				dis[j]=min(dis[j],g[x].w);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
