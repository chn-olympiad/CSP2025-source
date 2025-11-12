#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int n,m,k,c[15],a[15][10005];
struct node {
	int v,w;
};
vector <node> adj[1000005];
int bfs(int s) {
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u=q.front();
		q.pop();
		for (auto [v,w]:adj[u]) {
			ans+=w;
			q.push(v);
			ans-=w;
		}
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for (int i=1,u,v,w;i<=m;i++) {
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	for (int i=1;i<=k;i++) {
		cin >> c[i];
		for (int j=1;j<=n;i++) {
			cin >> a[i][j];
		} 
	}
	int ans=0x3f3f3f3f;
	for (int q=1;q<=n;q++) {
		int cnt=bfs(q);
		ans=min(ans,cnt);
	}
	cout << ans;
	return 0;
}
