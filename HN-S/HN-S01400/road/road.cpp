#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
const int N = 2e4 + 5;
typedef long long ll;
int tol;
ll a[12][N], c[N];
int n, m, k;
bool f[N];
struct node{
	int to;
	ll cost;
	bool operator<(const node &s) const{
		return s.cost < cost;
	}
};
vector<node>g[N];
bool vis[N];
ll ans = 1e18;
const ll INF = 1e18;
ll prim(ll ew){
	ll sum = 0;
	for(int i = 1; i <= n + k; i++){
		vis[i] = false;
	}
	priority_queue<node> que;
	que.push(node{1, 0LL});
	while(!que.empty()){
		node tmp = que.top();
		que.pop();
		int u = tmp.to;
//		cout << "u = " << u << " w = " << tmp.cost << "\n";
		if(vis[u]){
			continue;
		}
		vis[u] = true;
		sum += tmp.cost;
		if(sum + ew > ans){
			return INF;
		}
		for(auto &e: g[u]){
			int v = e.to;
			if(!vis[v]){
				que.push(e);
			}
		}
	}
//	cout << "sum = " << sum << "\n";
	return sum;
}
inline void add(int u, int v, ll w){
	g[u].emplace_back(node{v, w});
}

void dfs(int u, ll sum){
//	cout << "f = " ;
//	cout << " k = " << k << " ";
//	for(int i = 1; i <= k; i++){
//		if(f[i]){
//			cout << i << " ";
//		}
//	}
//	cout << "\n";
	ll p = prim(sum);
//	cout << "p = " << p << " ck = " << sum << " psum = " << p + sum << "\n";
	ans = min(ans, p + sum);
	if(u == k){
		return;
	}
	dfs(u + 1, sum);
	for(int j = 1; j <= n; j++){
		add(u + 1 + n, j, a[u + 1][j]);
		add(j, u + 1 + n, a[u + 1][j]);
	}
	f[u + 1] = true;
	dfs(u + 1, sum + c[u + 1]);
	f[u + 1] = false;
	for(int j = 1; j <= n; j++){
		g[u + n + 1].pop_back();
		g[j].pop_back();
	}
}
void solve(){
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v;
		ll w;
		cin >> u >> v >> w;
		g[u].push_back(node{v, w});
		g[v].push_back(node{u, w});
//		cout << "ok = " << i << " \n";
	}
//	cout << "ok1\n";
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
//	cout << "ok2\n";
	dfs(0, 0);
//	ans = prim();
	cout << ans << "\n";
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
}
