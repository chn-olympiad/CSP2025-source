#include <bits/stdc++.h>
using namespace std;
int a[500010], n, k, xsum[500010], dp[500010];
void solve(){
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		xsum[i] = xsum[i-1] ^ a[i];
	}
	for (int i=1; i<=n; i++){
		dp[i] = dp[i-1];
		for (int j=1; j<=i; j++){
			if (xsum[i] ^ xsum[j-1] == k){
				dp[i] = max(dp[i], dp[j-1] + 1);
			}
		}
	}
//	for (int i=1; i<=n; i++){
//		cout << dp[i] << " ";
//	}
	cout << dp[n];
} 

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
}
