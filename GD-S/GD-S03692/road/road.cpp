#include <bits/stdc++.h>
using namespace std; 
using ll = long long;
const int kMaxN = 1e6+2;
struct ip{
	int v,cost;
	ip(int a,int b):v(a),cost(b){
	}
};

struct ipp{
	int u,dist;
	ipp(int a,int b):u(a),dist(b){
	}
	bool operator<(const ipp& other) const {
		return dist>other.dist;
	}
};

int n,m,k;
int new_town[11];
vector<ip> rebuild_road[kMaxN];
int new_road[11][1001];

bool vis[kMaxN+10];
int dist[kMaxN+10];
int weight[kMaxN+10];

int Prims(int s) {
	int tot{0}; 
	dist[s]=0;
	weight[s]=0;
	priority_queue<ipp> pq;
	pq.emplace(s,0);
	
	while(!pq.empty()) {
		int u = pq.top().u;
		int Current_dist = pq.top().dist;
		vis[u]=1;
		pq.pop();
		
		if (Current_dist>dist[u]) {
			continue;
		}
		tot+=weight[u];
		for (auto next:rebuild_road[u]) {
			int v = next.v;
			int cost = next.cost;
			
			if (dist[u]+cost<dist[v]) {
				dist[v]=dist[u]+cost;
				weight[v]=cost;
				if (!vis[v]) {
					pq.emplace(v,dist[v]);
				}
			}
		}
	}
	return tot;
}

signed main(void) {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	cin>>n>>m>>k;
	for (int i=1;i<=m;i++) {
		int u,v,c;
		cin>>u>>v>>c;
		rebuild_road[u].emplace_back(v,c);
		rebuild_road[v].emplace_back(u,c);
	}
	for (int i=1;i<=k;i++) {
		cin>>new_town[i];
		for (int j=1;j<=n;j++) {
			cin>>new_road[i][j];
		}
	}
	fill(dist,dist+kMaxN+10,0x3f3f3f3f);
	cout<<Prims(1);
	return 0;
}

