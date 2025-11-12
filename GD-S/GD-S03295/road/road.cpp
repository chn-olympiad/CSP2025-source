#include<bits/stdc++.h> 
using namespace std;
#define cfalse cin.tie(0)->sync_with_stdio(0)
#define int long long
const int maxn = 2e6 + 5;
int n, m, k;
int ans = 0x3f3f3f3f;
bool vis[maxn];
bool vis1[maxn];
int cs[maxn];
struct edge{
	int v, w;
};
vector<edge>mp[maxn];
void dfs(int p, int num, int cnt){
//	if(cnt > ans)return; 
	if(num == n){
		ans = min(ans, cnt);
//		for(int i = 1; i <= k; i++){
//			cout << vis1[i] << endl;
//		}
//		cout <<cnt << ' ' << s << endl;
		return;
	}
	for(int i = 0; i < mp[p].size(); i++){
		int vv = mp[p][i].v, ww = mp[p][i].w;
		if(vv > n){
			vv -= n;
			if(vis1[vv]){
//				continue;
				dfs(vv + n, num, cnt + ww); 
			}else{
//				cout << vv << endl;
//				vis1[vv]++;
//				cout << vis1[vv] << endl;
				vis1[vv] = 1;
				
				dfs(vv + n, num, cnt + ww + cs[vv]);
				vis1[vv] = 0;
			}
			continue;
		}
		if(vis[vv])continue;
		vis[vv] = 1;
		dfs(vv, num + 1, cnt + ww);
		vis[vv] = 0;
	}
}
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(vis1, 0, sizeof(vis1));
	cfalse;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		mp[u].push_back({v, w});
		mp[v].push_back({u, w});
	} 
	bool flag = 1;
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		cs[i + 1] = x;
		if(x != 0)flag = 0;
		for(int j = 1; j <= n; j++){
			int g;
			cin >> g;
			mp[n + i + 1].push_back({j, g});
			mp[j].push_back({n + i + 1, g});
			if(g != 0)flag = 0;
		}
	}
//	deb();
	if(flag){
		cout << 0;
		return 0;
	}
	vis[1] = 1;
	dfs(1, 1, 0);
	cout << ans;
	return 0;
} 
