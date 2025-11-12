#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int N = 1e4+10,M = 1e6+10,K = 15;
struct edge{
	int v,w;
};
vector<edge> g[N];
int c[K];
int a[K][N];
bool vis[N];
long long ans = LONG_LONG_MAX;
void dfs(int u,long long s,int cnt){
	if(s>ans) return;
	if(cnt==n){
		ans = min(ans,s);
		return;
	}
	for(auto e : g[u]){
		if(!vis[e.v]){
			vis[e.v] = 1;
			dfs(e.v,s+e.w,cnt+1);
			vis[e.v] = 0;
		}
	}
}
void solve1(){
	for(int i = 1;i<=n;i++){
		vis[i] = 1;
		dfs(i,0,1);
		vis[i] = 0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	if(k==0) solve1();
	cout<<ans;
	return 0;
}
