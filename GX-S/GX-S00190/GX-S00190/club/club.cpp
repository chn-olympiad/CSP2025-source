#include <bits/stdc++.h>
using namespace std;
int m = -1, a[100005][3];
void dfs(int x, int y, int z, int n, int ans, int p){
	if(n == -1){
		m = max(m, ans);
		return;
	}
	for(int i = 0; i < 3; i++){
		if(x < p && i == 0){
			dfs(x + 1, y, z, n-1, ans + a[n][i], p);
		}
		if(y < p && i == 1){
			dfs(x, y + 1, z, n-1, ans + a[n][i], p);
		}
		if(z < p && i == 2){
			dfs(x, y, z + 1, n-1, ans + a[n][i], p);
		}
	}
	return;
}
int main(void){

	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t, n, k[100005];
	cin >> t;
	for(int o = 0; o < t; o++){
		cin >> n;
		int x = 0, y = 0, z = 0, p = n / 2;
		for(int i = 0; i < n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		dfs(x, y, z, n-1, 0, p);
		k[o] = m;
		m = -1;
		for(int i = 0; i < n; i++){
			a[i][0] = a[i][1] = a[i][2] = 0;
		}
	}
	for(int i = 0; i < t; i++){
		cout << k[i] << endl;
	}
	
	
	return 0;
}
