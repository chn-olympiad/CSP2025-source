#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5005, mod = 998244353;
int n, A[N], S[N];

int dp[N * N], ans;

signed main() {
//	freopen("polygon4.in", "r", stdin);
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i ++) cin >> A[i];
	sort(A + 1, A + n + 1);
	for(int i = 1; i <= n; i ++) S[i] = S[i - 1] + A[i];
	
	dp[0] = 1;
	for(int j = 1; j <= S[n]; j ++) dp[j] = 0;
	for(int k = S[1]; k >= A[1]; k --) {
		dp[k] = (dp[k] + dp[k - A[1]]) % mod;
	}
	for(int i = 3; i <= n; i ++) {
		for(int k = S[i - 1]; k >= A[i - 1]; k --) {
			dp[k] = (dp[k] + dp[k - A[i - 1]]) % mod;
		}
		
		if(S[i - 1] <= A[i]) continue;
		for(int j = A[i] + 1; j <= S[i - 1]; j ++) ans = (ans + dp[j]) % mod;
//		cerr<<i<<"::"<<ans<<"\n";
	}
	cout << ans;
	return 0;
}
