#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,INF=1e9+5;

vector<long long> dijkstra(int start,int n,vector<vector<pair<int,int>>> &adj){
	vector<long long> dist(n);
	dist[start]=0;
	dist[n]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<int>> pq;
	for(int i=1;i<=n;i++){
		
	}
	return dist;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("raod.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<pair<int,int>>> adj;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].emplace_back(v,w);
		adj[v].emplace_back(u,w);
	}
	vector<long long> dist=dijkstra(1,n,adj);
	cout<<dist[n];
	
	return 0;
}
