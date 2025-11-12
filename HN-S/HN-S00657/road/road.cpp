#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
bool vis[N+K];
int ans=0x3f3f3f3f;
int c[K];
vector<pair<int,int> > e[N];
void dfs(int x,int sum){
	vis[x]=1;
	int f=1;
	for(int i=1;i<=n;i++){
		if(vis[i]==0) {f=0; break;}
	}
	if(f==1){
		ans=min(ans,sum);
		return;
	}
	for(int i=0;i<e[x].size();i++){
		int y=e[x][i].first;
		int z=e[x][i].second;
		if(vis[y]) continue;
		vis[y]=1;
		if(y<=n){
			dfs(y,sum+z);
		}
		else if(y>n) dfs(y,sum+z+c[y-n]);
		vis[y]=0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
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
			int a;
			cin>>a;
			e[n+i].push_back({j,a});
			e[j].push_back({n+i,a});
		}
	}	
	dfs(1,0);	
	cout<<ans;
	return 0;
}
