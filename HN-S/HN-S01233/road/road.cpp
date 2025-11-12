#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 5;
ll k, m, n, c[N], a[15][N];
bool vis[N];
struct node{
	ll v, w;
	bool operator < (const node &s1)const{
		return w > s1.w;
	}
};
vector<node>e[N];
priority_queue<node>q;
ll dij(){
	ll cnt = 0;
	q.push({1, 0});
	while(!q.empty()){
		node tmp = q.top();
		q.pop();
		ll u = tmp.v;
		if(vis[u]){
			continue;
		}
		vis[u] = 1;
		cnt++;
		if(cnt == n){
			return tmp.w;
		}
		for(int i = 0; i < e[u].size(); i++){
			ll v = e[u][i].v;
			q.push({v, tmp.w + e[u][i].w});
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
		e[v].push_back({u, w});
	}
	if(k == 0){
		cout << dij();
		return 0;
	}
	for(int i = 1; i <= k; i++){
		cin >> c[i];
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(!a[i][j]){
				e[i + n].push_back({j, 0});
				e[j].push_back({i + n, 0});
			}
		}
	}
	cout << dij();
	return 0;
}
