#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 113;
vector<pair<int,int> >adj[N];
int n,m,k;
bool vis[N];
int a[N];
int main(){
	freopen("road1.in","r",stdin);
//	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		
	}
	set<int> st;int w[N];
	memset(w,0,sizeof(w));
	for(int i = 1;i <= k;i++){
		cin >> a[i];
		for(int j = 1;j <= n;j++){
			cin >> w[j];
		}
		for(int u = 1;u <= n;u++){
			for(int j = 0;j < adj[u].size();j++){
				int v = adj[u][j].first,_w = adj[u][j].second;
				if(w[v] + w[u] + int(!vis[u]) * a[i] <= _w){
					adj[u][j].second = w[v] + w[u] + int(!vis[u]) * a[i];
					if(!vis[u]){
						vis[u] = 1;
					}
				}
			}
		}
	}
	int ans = 0;
	st.insert(1);
	for(int l = 1;l <= n - 1 + k;l++){
	
		int min_v = 0,min_u = 0;int w = 0x3f3f3f;
		for(int u = 1;u <= n;u++){
//			cout << st.count(u) << '\n';
			if(!st.count(u)){
				continue;
			}
			for(int j = 0;j < adj[u].size();j++){
				int v = adj[u][j].first,_w = adj[u][j].second;
				if(st.count(v)){
					continue;
				}
				if(v > m && !vis[v]){
					_w + a[v];
				}
//				cout << u << ' ' << v << ' ' << _w<< '\n';
				if(_w < w){
					
					w = _w;
					min_v = v;
				}
			}
		}
		st.insert(min_v);
		ans += w;
		if(min_v > m){
			vis[min_v] = 1;
		}
		
	}
	cout << ans << '\n';
	return 0;
}
