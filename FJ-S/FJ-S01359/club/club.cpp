#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int t, n, a[N][5];
long long res;
void dfs(int hang, long long sum, int x, int y, int z){
	if (hang > n){
		res = max(res, sum);
		return;
	}
	for (int i = 1; i <= 3; i++){
		if (i == 1 && x < n/2) dfs(hang+1, sum+a[hang][i], x+1, y, z);
		else if (i == 2 && y < n/2) dfs(hang+1, sum+a[hang][i], x, y+1, z);
		else if (i == 3 && z < n/2) dfs(hang+1, sum+a[hang][i], x, y, z+1);
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--){
		res = 0;
		cin >> n;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		dfs(1, 0, 0, 0, 0);
		cout << res <<"\n";
	}
	
	return 0;
}
