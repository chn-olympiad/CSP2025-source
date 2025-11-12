#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt,ans,s;
vector<int> v(10015);
vector<vector<pair<int,int>>> adj(10015);
priority_queue<pair<int,int>> q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({w,v});
		adj[v].push_back({w,u});
	}
	for(int i=1;i<=k;i++) {
		int x;
		cin>>x;
		for(int j=1;j<=n;j++) {
			int y;
			cin>>y;
			adj[j].push_back({x+y,i+m});
			adj[i+m].push_back({y,j});
		}
	}
	q.push({0,1});
	s=n;
	while(s) {
		auto t=q.top();
		q.pop();
		int x=-t.first,y=t.second;
		if(v[y]) continue;
		ans+=x;
		v[y]=1;
		if(y<=n) s--;
		for(auto i:adj[y]) {
			i.first=-i.first;
			q.push(i);
		}
	}
	cout<<ans;
	
	return 0;
}
