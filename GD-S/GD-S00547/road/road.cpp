#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int oa[10000][10000];
signed main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(oa, 0x3f3f3f3f, sizeof oa);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		oa[u][v] = min(oa[u][v], w);
	}
	if(k == 0){
		int ans = 0;
		for(int i = 1; i <= 900; i++){
			for(int j = 1; j <= 900; j++){
				if(oa[i][j] != 0x3f3f3f3f){
					ans += oa[i][j];
				}
			}
		}
		cout << ans <<'\n';
		return 0;
	}
	return 0;
}

/*
4 4 0
1 4 6
2 3 7
4 2 5
4 3 4
*/
