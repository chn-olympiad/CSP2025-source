#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e2 + 7, maxs = 5e4 + 7, mod = 998244353;
int dp[maxn][maxs];
int a[maxn];
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, W = 0;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		W += a[i];
	}
	sort(a + 1, a + 1 + n);
	dp[0][0] = 1;
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= W; j++){
			for(int k = i + 1; k <= n; k++) dp[k][j + a[k]] = (dp[k][j + a[k]] + dp[i][j]) % mod;
		}
	}
	long long ans = 0;
	for(int i = 3; i <= n; i++){
		for(int j = 2 * a[i] + 1; j <= W; j++){
			ans = (dp[i][j] + ans) % mod;
		}
	}
	cout << ans << endl;
	return 0;
}
//T4好难不会做哇
//测了一下应该能拿40pts
//祝我好运 
