#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define mp make_pair
#define pii pair<int, int>
#define N (int)1e5 + 10
#define inf 0x3f3f3f3f

int n, m, k, dis[N], cities[N][N];
bool vis[N];
struct edge {
  int v, w;
};
struct node {
  int u, dis;
};

bool cmp(node a, node b) {
  return a.dis < b.dis;
}
vector<edge> E[N];

void dij(int n, int s) {
  memset(dis, inf, sizeof(dis));
	queue<node> q;
  q.push((node){s, 0});
  while (!q.empty()) {
    node u = q.front();
    q.pop();
    for (edge i : E[u.u]) {
      if (u.dis + i.w < dis[i.v]) {
        dis[i.v] = u.dis + i.w;
        q.push((node){i.v, dis[i.v]});
      }
    }
  }

  return ;
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }
  
  for (int i = 1; i <= k; i++) {
  	cin >> cities[i][0];
  	for (int j = 1; j <= n; j++) {
  		cin >> cities[i][j];
  		  E[i].push_back({j, 0});
    		E[j].push_back({i, 0});
		}
	}
	dij(n, 1);
  cout << dis[n] << endl;
  
  return ;
}

int main() {
  cin.tie(0);
  cout.tie(0);

  freopen("road.in", "r", stdin); 
  freopen("road.out", "w", stdout);

  solve();

  return 0;
}
