#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+114;

struct Ed{
	ll u,cost;
};

bool cmp(Ed q, Ed p){
	return q.cost<p.cost;
}
int n,m,k;
vector<Ed> G[N];
ll pf[20];
ll ans=0;
ll dis[N];
bool vis[N];


void solve(){
	for(int i=2;i<=n;i++){
		dis[i]=2000000000;
	}
	dis[0]=2000000000;
	dis[1]=0;

	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(!vis[j] && dis[j]<dis[u]) u=j;
		}
		vis[u]=1;
		if(!u)break;
		for(int j=0;j<G[u].size();j++){
			Ed v=G[u][j];
			//cout<<v<<endl;
			if(dis[v.u]>dis[u]+v.cost){
				dis[v.u]=dis[u]+v.cost;
			}
		}
		
	}
		
	cout<<ans<<endl;
	
	
}







int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	
	
	cin>>n>>m>>k;
	int x,y,z;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		G[x].push_back({y,z});
		G[y].push_back({x,z}); 
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<G[i].size();j++){
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=k;i++){
		cin>>pf[i];
		int o;
		for(int j=1;j<=n;j++){
			cin>>o;
			G[j].push_back({i+n,o});
			G[i+n].push_back({j,o});
		}
	}
	solve();
	
	fclose(stdin);
	fclose(stdout);
	
	
	
	return 0;
} 
