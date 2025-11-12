#include <bits/stdc++.h>
using namespace std;
int a[10015][10015];
int n, m, k;
void turn_zero(int i){
	for(int j = 1; j <= n; j++){
		if(a[i][j] != 0){
			a[i][j] = 0;
			turn_zero(j);
		}
	}
}
int main(){
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int ans = 0;
	cin >> n >> m >> k;
	int u, v, w;
	int town[15];
	int min_index_i = 0;
	int min_index_j = 0;
	a[0][0] = 1000000;
	for(int i = 1; i <= m; i++){
		cin >> u >> v >> w;
		a[u][v] = w;
		a[v][u] = w;
		if(a[min_index_i][min_index_j] > a[u][v]){
				min_index_i = u;
				min_index_j = v;
		}
	}
	int index = m+1;
	for(int i = 1; i <= k; i++){
		cin >> town[i];
		for(int j = 1; j <= n; j++){
			cin >> a[index][j];
			a[index][j] += town[i];
			a[j][index] = a[index][j];
			if(a[min_index_i][min_index_j] > a[index][j]){
				min_index_i = index;
				min_index_j = j;
			}
			index++;
		}
	}
	ans += a[min_index_i][min_index_j];
	turn_zero(min_index_i);
	while(true){
		int min_index_i1 = 0;
		int min_index_j1 = 0;
		for(int i = 1; i <= n+m; i++){
			for(int j = 1; j <= n+m; j++){
				if(a[min_index_i1][min_index_j1] > a[i][j]){
					min_index_i = index;
					min_index_j = j;
				}
			}
		}
		if(min_index_i1 == 0 && min_index_j1 == 0){
			break;
		}
		ans += a[min_index_i1][min_index_j1];
		turn_zero(min_index_i1);
	}
	cout << ans;
	return 0;
}
