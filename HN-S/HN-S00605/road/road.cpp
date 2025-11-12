#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct node{
	int v,w;
};
void dfs(int c)
vector<node> maze[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int ans=0;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		maze[u].push_back({v,w});
		maze[v].push_back({u,w});
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int c[10015];
		cin>>c[n+i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			maze[n+i].push_back({j,w})
		}
	}
	cout<<ans;
	return 0;
}
