#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e6 + 10 + 5;
struct city{
	int v,w;
};
struct node{
	ll sum;
	int w,u;
};
typedef pair<ll,int> pii;
vector<city> side[N];
bool vis[N];
node dis[N];
int country[15];
bool vis2[15];
void solve(){
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1 ; i <= m ; i++ ){
		int u,v,w;
		cin >> u >> v >> w;
		side[u].push_back({v,w});
		side[v].push_back({u,w});
	}
	for(int i = 1 ; i <= k ; i++ ){
		int c;
		cin >> c;
		for(int j = 1 ; j <= n ; j++ ){
			int a;
			cin >> a;
			side[n + i].push_back({j,a});
			side[j].push_back({n + i,a + c});
		}
	}
	for(int i = 1 ; i <= n + k ; i++ ){
		dis[i] = {0x3f3f3f3f,0x3f3f3f,0};
	}
	dis[1] = {0,0};
	priority_queue<pii,vector<pii>,greater<pii>>q;
	q.push({0,1});
	while(q.size()){
		ll sum = q.top().first;
		int u = q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u] = true;
		for(auto [v,w] : side[u]){
			if(dis[v].w > w){
				dis[v].sum = sum + w;
				dis[v].w = w;
				vis[v] = false;
				if(u > n) dis[v].u = u;
				else dis[v].u = 0;
				q.push({dis[v].sum,v});
			}
		}
	}
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++ ){
		if(dis[i].sum == 0x3f3f3f3f) continue;
		ans += dis[i].w;
		if(dis[i].u <= n || vis2[dis[i].u]) continue;
		ans += dis[dis[i].u].w;
		vis2[dis[i].u] = true;
	}
	cout << ans;
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
