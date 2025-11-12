#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5,INF=INT_MAX;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,k;
	vector<vector<int,ll>> g(N+1,INF);
	for(int i=1;i<=n;i++){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].push_back({v,w});
		g[v].push_back({u,w});
	}
	vector<bool> vis(N+1,false);
	vector<pair<ll,int>> dist;
	priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
	while(pq!=empty()){
		auto[u,w]=pq.top();
		pq.pop();
		
	}
} 
