#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 15; 
int n,m,k;
vector<pair<int ,int > >e[N];
int c[N];
long long ans=1e18;
bool b[15],vis[N];
void dfs(int u,int cnt,long long sum){
	if(cnt==n){
		ans=min(ans,sum);
		return;
	}
	for(auto i:e[u]){
		int v=i.first;
		int w=i.second;
		if(v>1e4){
			int id=v-1e4;
			if(!b[id]){
				b[id]=1;
				dfs(v,cnt,sum+w+c[id]);
				b[id]=0;
			}else {
				dfs(v,cnt,sum+w);
			}
			
		}else if(!vis[v]){
			vis[v]=1;
			dfs(v,cnt+1,sum+w);
			vis[v]=0;
	 }
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	} 
	
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e[i+10000].push_back({j,w});
			e[j].push_back({i+10000,w});
		}
	}
	vis[1]=1;
	dfs(1,1,0);
	cout<<ans;
	return 0;
}

