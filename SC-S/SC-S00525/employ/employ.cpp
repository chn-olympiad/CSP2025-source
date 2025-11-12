#include<bits/stdc++.h>
using namespace std;
bitset<500>s;
const int mod = 998244353;
int c[510];
int dp[510][510];
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	cin >> s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c[i];j++){
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%mod;
		}
		for(int j=c[i]+1;j<=n;j++)dp[i][j]=(dp[i][j-1]+dp[i-1][j])%mod;
	}
	cout<<dp[n][n];
//	if (s.count() == n || m == 1) {
//		int ans = 1;
//		for (int i = 1; i <= n; i++) {
//			ans = 1ll * ans * i % mod;
//		}
//		cout << ans;
//	} else if (n <= m) {
//		cout << 0;
//	}
}