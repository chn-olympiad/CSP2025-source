#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n, a[5010], dp[2][5010], pw[5010], ans;
signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	sort(a+1, a+n+1);
	pw[0] = 1;
	for (int i=1; i<=n; i++)
		pw[i] = pw[i-1] * 2 % mod;
	dp[0][0] = 1;
	for (int i=1; i<=n; i++){
		int cur=i%2, lst=cur^1, k=0;
		for (int j=0; j<=a[i]; j++)
			(k += dp[lst][j]) %= mod;
		(ans += pw[i-1] - k) %= mod;
		memset(dp[cur], 0, sizeof(dp[cur]));
		for (int j=0; j<=5000; j++){
			dp[cur][j] = dp[lst][j];
			if (j >= a[i])
				dp[cur][j] += dp[lst][j-a[i]];
		}
	}
	cout << (ans + mod) % mod;
}