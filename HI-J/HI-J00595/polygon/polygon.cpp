#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5010,mod = 998244353;
int n;
int a[N];
int dp[N],sum;
int ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 5001; j > a[i]; j--) {
			ans = (ans + dp[j]) % mod;
		}
		sum += a[i];
		if (sum > 5001) {
			for (int j = 5001; j >= 5001 - a[i]; j--) {
				dp[5001] = (dp[5001] + dp[j]) % mod;
			}
			for (int j = 5000; j >= a[i]; j--) {
				dp[j] = (dp[j] + dp[j - a[i]]) % mod;
			}
		}
		else {
			for (int j = sum; j >= a[i]; j--) {
				dp[j] = (dp[j] + dp[j - a[i]]) % mod;
			}
		}
//		for (int i = 1; i <= sum; i++) {
//			cout << dp[i] << " ";
//		}
//		cout << "\n";
	}
	cout << ans;
	return 0;
}
