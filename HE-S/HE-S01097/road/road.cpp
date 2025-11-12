#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 20;

int n,m,k,a[15][N],dis[N],ans,p[N],id;
vector <pair<int,int> > g[N];
bool vis[N],vis1[N];
priority_queue <pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;

void dijstra (int s) {
	
	memset (dis,0x3f3f3f3f,sizeof(dis));
	q.push(make_pair(0,s));
	dis[s] = 0;
	
	while (!q.empty()) {
		
		int u = q.top().second;
		q.pop();
		
		if (vis[u]) continue;
		vis[u] = true;
		
		for (auto e : g[u]) {
			int v = e.first;
			int w = e.second;
			
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(make_pair(dis[v],v));
			}
			
		}
		
	}
	
}

int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m >> k;
	
	for (int i = 1,u,v,w;i <= m;i ++) {
		cin >> u >> v >> w;
		g[u].push_back(make_pair(v,w));
		g[v].push_back(make_pair(u,w));
	}
	
	id = n + k;
	
	for (int i = n + 1;i <= n + k;i ++) {
		cin >> p[i];
		for (int j = 1;j <= n;j ++) {
			cin >> a[i][j];
			if (j == 1) {
				id ++;
				g[id].push_back(make_pair(i,a[i][j]));
				g[i].push_back(make_pair(id,a[i][j]));
			} else {
				g[i].push_back(make_pair(j,a[i][j]));
				g[j].push_back(make_pair(i,a[i][j]));
			//	cout << id << ' ';
			}
		}
	}
	
	for (int i = n + k + 1;i <= id;i ++) {
		g[1].push_back(make_pair(i,p[i - k]));
		g[i].push_back(make_pair(1,p[i - k]));
	}
	
	for (int i = 1;i <= n;i ++) {
		ans += dis[i];
	}
	
	cout << ans << '\n'; 
	return 0;
}

