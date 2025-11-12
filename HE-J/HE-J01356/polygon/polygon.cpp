#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n, a[5005], ans = 1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];	
	}
	for (int i = 1; i <= n; i++){
		ans = (ans * 2) % MOD;
	}
	ans = (ans - n + MOD) % MOD;
	ans = (ans - n * (n - 1) / 2 + MOD) % MOD;
	cout << ans;
	return 0;
}
