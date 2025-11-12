#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5010 , Mod = 998244353;
int n , a[N] , dp[2 * N] , ans , f[N]; 
signed main () {
	freopen ("polygon.in" , "r" , stdin);
	freopen ("polygon.out" , "w" , stdout); 
	ios::sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	cin >> n;
	for (int i = 1;i <= n;i ++) cin >> a[i];	
	sort (a + 1 , a + n + 1);
	dp[0] = 1;
	//dp[a[1]] = 1;
	for (int i = 1;i <= n;i ++) {
		memset (f , 0 , sizeof f);
		for (int j = 5001;j > a[i];j --) {
			ans = (ans + dp[j]) % Mod;
		}
		for (int j = 10000;j >= a[i];j --) {
			f[j] += dp[j - a[i]];
			int x = min (j , 5001ll);
			f[x + 1] -= dp[j - a[i]];
		}
		dp[0] += f[0];
//		for (int j = 0;j <= 15;j ++) cout << f[j] << ' ';
//		cout << '\n';
		for (int j = 1;j <= 5002;j ++) {
			f[j] += f[j - 1];
			dp[j] = (dp[j] + f[j]) % Mod;
		}
//		for (int j = 0;j <= 15;j ++) cout << dp[j] << ' ';
//		cout << '\n';
	}
	cout << ans;
	return 0;
}
