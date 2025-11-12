#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct edge{
	int to,dist;
};
int n,m,k,u,v,w;
vector<edge>g[N];
bool vis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	while(m--){
		cin>>u>>v>>w;
		g[u].push_back({v,w}),g[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
		}
	}
	cout<<0;
	return 0;
}
