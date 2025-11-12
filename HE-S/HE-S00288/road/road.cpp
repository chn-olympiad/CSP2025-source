#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
using namespace std;
const int N = 1e4 + 50;

ll n, m, k, c[15], a[15][N], minn = 4e18, dis[N];
bool vis[N];
vector<pair<int, ll> > e[N];
struct Node{
	ll w;
	int id;
	bool operator<(const struct Node &T) const{
		return w > T.w;
	}
};
priority_queue<Node> q;

ll Prim(int sum){
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[1] = 0;
	while(!q.empty()) q.pop();
	q.push({0, 1});
	
	int tot = 0;
	ll ans = 0;
	while(!q.empty()){
		int u = q.top().id;
		q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		tot++;
		ans += dis[u];
		//cout << dis[u] << '\n'; 
		if(tot == sum) break;
		
		for(auto v : e[u]){
			if(dis[v.fi] > v.se){
				dis[v.fi] = v.se;
				q.push({dis[v.fi], v.fi});
			}
		}
	}
	return ans;
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m >> k;
	for(int i = 1, u, v, w;i <= m;i++){
		cin >> u >> v >> w;
		e[u].push_back(mp(v, w));
		e[v].push_back(mp(u, w));
	}
	
	for(int i = 1;i <= k;i++){
		cin >> c[i];
		for(int j = 1;j <= n;j++){
			cin >> a[i][j];
		}
	}
	
	for(int s = 0;s <= (1 << k) - 1;s++){
		int cnt = n;
		ll ans = 0;
		for(int i = 0;i < k;i++){
			if(s & (1 << i)){
				cnt++;
				ans += c[i + 1];
				for(int j = 1;j <= n;j++){
					e[cnt].push_back(mp(j, a[i + 1][j]));
					e[j].push_back(mp(cnt, a[i + 1][j]));
				}
			}
		}
		ans += Prim(cnt);
		//cout << s << ' ' << ans << '\n'; 
		minn = min(minn, ans);
		
		for(int i = n + 1;i <= cnt;i++) e[i].clear();
		for(int i = 1;i <= n;i++){
			for(int j = n + 1;j <= cnt;j++){
				e[i].pop_back();
			}
		}
		
//		for(int i = 1;i <= cnt;i++){
//			cout << e[i].size() << '\n';
//			for(auto v : e[i]){
//				cout << i << '\n';
//				cout << i << ' ' << v.fi << '\n';  
//			}
//		}
	}
	cout << minn << '\n';
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/

