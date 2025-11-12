#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, mn[15], t[10010], cnt;
struct Per{
	int first, second;
};
signed main(){
	vector<Per> q[10010ll];
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, p;
		cin >> u >> v >> p;
		q[u].push_back({v, p});
		q[v].push_back({u, p});
	}
	for(int i = 1; i <= k; i++){
		int p;
		cin >> p;
		mn[i] = p;
		for(int j = 1; j <= m; j++){
			int v;
			cin >> v;
			q[m + i].push_back({j, v});
			q[j].push_back({m + i, v});
		}
	}
	t[1] = 1;
	for(int i = 1; i <= n; i++){
		int minn = 1e9, x, y;
		Per p;
		for(int j = 1; j <= q[i].size(); j++){
			if(q[i][j].first <= minn && !t[q[i][j].first]){
				minn = q[i][j].second;
				p = q[i][j];
				x = i;
				y = j;
			}
		}
		t[p.first] = 1;
		if(p.first > m){
			cnt += mn[p.first - m];
			mn[p.first - m] = 0;
		}
		cnt += p.second;
		q[x][y] = {1e10, 1e10};
		bool f = 1;
		for(int i = 1; i <= m; i++){
			if(!t[i]){
				f = 0;
				break;
			}
		}
		if(f){
			cout << cnt;
			return 0; 
		}
	}
	cout << cnt;
	return 0;
}
