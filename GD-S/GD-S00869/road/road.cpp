#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<pair<int,int>>g[10005];
int t[15][10005];
int c[15];
int f[10005];
bool vis[10005];
priority_queue<pair<int,int>>q;
int ans;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int dis=0x7f7f7f7f7f7f7f7f;
			for(int town=1;town<=k;town++){
				dis=min(dis,c[town]+t[town][i]+t[town][j]);
			}
			g[i].push_back({j,dis});
			g[j].push_back({i,dis});
		}
	} 
	memset(f,0x7f,sizeof(f));
	q.push({0,1});
	f[1]=0;
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u]){
			continue;
		}
		//cout<<u<<" "<<f[u]<<"\n";
		vis[u]=1;
		ans+=f[u];
		for(auto i:g[u]){
			int v=i.first;
			int w=i.second;
			if(f[v]>w){
				f[v]=w;
				q.push({-f[v],v});
			}
		}
	}
	cout<<ans;
	return 0;
}

