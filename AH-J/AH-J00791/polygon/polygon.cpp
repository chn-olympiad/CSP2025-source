#include<bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAXN = 5005;
const int MAXNUM = 10005;

int n;
int l[MAXN];
long long ans = 0;
long long dp[MAXNUM];

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; ++i) scanf("%d", &l[i]);
	sort(l + 1, l + n + 1);
	dp[0] = 1;
	long long pow2 = 1;
	for (int i = 1; i <= n; ++i) {
		long long sum = 0;
		for (int j = 0; j <= l[i]; ++j) sum = (sum + dp[j]) % MOD;
		ans = ( ans +  ( (pow2 - sum) % MOD ) ) % MOD;
		pow2 = ( pow2 * 2 ) % MOD;
		for (int j = 5000; j >= l[i]; --j) dp[j] = ( dp[j] + dp[ j - l[i] ] ) % MOD;
	}
	ans = (ans + MOD) % MOD;
	cout << ans << endl;
	
	return 0;
}
