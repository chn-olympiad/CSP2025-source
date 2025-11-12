#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+10,MAXK=15,MAXSUM=1e6+10;
int c[MAXN],a[MAXK][MAXN],dist[MAXN],vis[MAXN],vis2[MAXN],check[MAXSUM];
struct Edge {
	int to,w;
};
vector<Edge>city[MAXN];
pair<int ,int >Section;
priority_queue<pair<int ,int > ,vector<pair<int ,int > > , greater<pair<int ,int >> >pq;
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		city[u].push_back({v,w});
		city[v].push_back({u,w});
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	pq.push({0,1});
	fill(dist+1,dist+n+1,1e9);
	dist[1]=0;
	vis2[1]=true;
	while(!pq.empty()) {
		int cur_dist=pq.top().first,cur_u=pq.top().second;
		pq.pop();
		for(auto nxt:city[cur_u]) {
			bool flag=false;
			if(nxt.to==n) {
				for(int i=1; i<n; i++) {
					if(vis2[i]==false) {
						flag=true;
						check[dist[cur_u]+nxt.w]=true;
						break;
					}
				}
				if(check[dist[cur_u]+nxt.w])continue;
			}
			if(flag)continue;
			vis2[nxt.to]=true;
			if(dist[nxt.to]>dist[cur_u]+nxt.w) {
				dist[nxt.to]=dist[cur_u]+nxt.w;
				pq.push({dist[nxt.to],nxt.to});
			}
		}
	}
	cout<<dist[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

