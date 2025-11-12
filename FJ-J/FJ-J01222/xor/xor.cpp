#include <bits/stdc++.h>
using namespace std;
const int M = 20005;
int n, k, ans = 0;
bool vis[M];
int arr[M], p[M][M];
int xr(int a, int b){
	return (a|b) - (a&b);
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
		p[i][i] = arr[i];
	}
	for (int i = 1; i <= n; i++){
		for (int j = i+1; j <= n; j++){
			p[i][j] = xr(p[i][j-1], p[j][j]);
		}
	}
	for (int a = 0; a < n; a++){
		int j = 0;
		for (int i = 1; i <= n && j <= n; i++){
			int j = i + a;
			if (p[i][j] == k){
				bool flag = false;
				for (int a = i; a <= j; a++){
					if (vis[a]) {
						flag = true;
						break;
					}
				}
				if (!flag){
					fill(vis+i, vis+j, true);
					ans ++;
				}
			}
		}
	}
	cout << ans;
	return 0;
}
