#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], ans, sum; 
void dfs(int x, int now, int g){
	if (g > n){
		return;
	}
	for (int i = g; i <= n; i++){
		sum += a[i];
		if (now == x){
			if (sum > a[i]*2){
				ans++;
			}
		}
		else{
			dfs(x, now+1, i+1);
		}
		sum -= a[i];
	}
}
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a+1, a+n+1);
	for (int i = 3; i <= n; i++){
		sum = 0;
		dfs(i, 1, 1); 
	}
	cout << ans % MOD;
	return 0;
}
