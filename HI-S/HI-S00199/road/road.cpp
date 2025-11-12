#include<bits/stdc++.h>
using namespace std;
int n,m,k;
bool vis[2000005];
struct Node{
	int to,w;
};
int c[15];
vector<Node>g[2000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		int u,v,w;
		cin>>u>>v>>w;                                                                                                                        
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	for(int i=0;i<k;i++){
		cin>>c[i];
		for(int j=0;j<n;j++){
			int v,w;
			cin>>v>>w;
			g[n+i+1].push_back({v,w});
			g[v].push_back({n+i+1,w});
		}
		
	}
	return 0;
}
