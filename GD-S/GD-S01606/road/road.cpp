#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e4+10, M = 2e6+10;
ll n, m, k;
ll c[15], a[15][N], to[N];
bool vis[N];
ll cur[N];
vector<pair<int, int> > rel[M];// first->点, second->c 

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		rel[u].push_back({v, w});
		rel[v].push_back({u, w});
	}
	for(int j = 1; j <= k; j++){
		cin >> c[j];
		for(int i = 1; i <= n; i++){
			cin >> a[j][i];
		}
	}
	memset(to, 0x3f, sizeof to);
	to[1] = 0;
	ll anss = 0;
	for(int i = 1; i <= n; i++){
		int id = INT_MAX, d = 0;
		for(int j = 1; j <= n; j++){
			if(to[j] <= id && !vis[j]) id = to[j], d = j;
		}
		anss += to[d];
		vis[d] = 1;
		int kkk = rel[d].size(); 
		for(int j = 0; j < kkk; j++){// 遍历每条边使与d链接的点全部更新 
			if(rel[d][j].second < to[rel[d][j].first]) to[rel[d][j].first] = rel[d][j].second;
		}
//		cout << d << '\n';
		// 再用村庄更新其他边 
		for(int i = 1; i <= k; i++){
			for(int j = 1; j <= n; j++){
				if(j == d || vis[j]) continue;
				to[j] = min(to[j], c[i] + a[i][d] + a[i][j]);
			}
		}
//		for(int i = 1; i <= n; i++) cout << to[i] << " ";
//		cout << '\n';
	}
	cout << anss << '\n';
	return 0;
} 
