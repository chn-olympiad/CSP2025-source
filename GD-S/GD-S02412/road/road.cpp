#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, k, note[2000];
vector<ll> mp[2000][2000];

int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(ll i = 1; i <= m; i++){
		ll u, v, w;
		cin >> u >> v >> w;
		mp[u][v] = mp[v][u] = w;
	}
	for(int i = 1; i <= k; i++){
		cin >> note[n + i];
		for(int j = 1; j <= n; j++){
			cin >> mp[j][n + i];
			mp[n + i][j] = mp[j][n + i];
		}
	}
	bfs();
	cout << note[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

