#include <bits/stdc++.h>
using namespace std;
int const N = 3e6 + 100;
#define int long long
struct jgt{
	int x, y;
}e[N];

int fee[20], dis[N], used[N];  	
int n, m, k, ans, cnt;
bool vis[N];
vector<pair<int, int>> v[N];
vector<int> yongt[N];
int dijk(){
	memset(dis, 0x3f, sizeof(dis));
	priority_queue<pair<int,pair<int, int> > > q;
	q.push({0, {1, 0}});
	dis[1] = 0;
	cnt = 0;
	while(q.size()){
		auto ceo = q.top(); q.pop();
		auto edge = ceo.second;
		auto x = edge.first;
		int y = edge.second;
		if(vis[x]) continue;
		vis[x] = 1;
		ans += dis[x];	
		if(x > n) used[x] = dis[x];   //x增加了值 
		if(y > n) yongt[y].push_back(x);
		 
		if(x <= n) cnt++;
		
		if(cnt >= n) return ans;
		for(auto e : v[x]){
			int to = e.first;
			int v = e.second;
			if(to > n) v += fee[to - n];
			int ndis = v;
			//cout << " to = " << to << " v = " << v << " dis[to] = " << dis[to] << " ndis = " << ndis << endl;
			if(ndis >= dis[to]) continue;
			dis[to] = ndis;
			q.push({-ndis, {to, x}});
		}
	}
	return 0;
}

int dfs(int x){
	if(x < n) {
		return true;
	}
	for(int to : yongt[x]){
		if(dfs(to)) return true;
	}
	return false;
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	
	for(int i = 1; i <= m; i++){
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({y, z});
		v[y].push_back({x, z});
	}
	for(int i = 1; i <= k; i++){
		cin >> fee[i];
		for(int j = 1; j <= n; j++){
			int z;
			cin >> z;
			int nt = n + i;    
			v[nt].push_back({j, z}); 
			v[j].push_back({nt, z});
		}
	}
	int tot = dijk();
	for(int i = 1; i <= k; i++){
		if(used[n+i]){
			if(!dfs(n + i)) tot -= used[n+i];
		}
	}
	cout << tot << endl;
	return 0;
}
