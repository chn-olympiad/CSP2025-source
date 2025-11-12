#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int a[N][4];
int ans, n, mx;
void dfs(int u, int num, int x, int y, int z){
	if(u == n + 1){
		ans = max(ans, num);
		return;
	}
	if(x < n / 2) dfs(u + 1, num + a[u][1], x + 1, y, z);
	if(y < n / 2) dfs(u + 1, num + a[u][2], x, y + 1, z);
	if(z < n / 2) dfs(u + 1, num + a[u][3], x, y, z + 1);
	return; 
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
		}
		ans = 0;
		dfs(0, 0, 0, 0, 0);
		cout << ans << '\n';
	}
	return 0;
} 