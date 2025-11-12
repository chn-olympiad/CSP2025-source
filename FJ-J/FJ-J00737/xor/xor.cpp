#include <bits/stdc++.h>	//60

using namespace std;

const int N = 5e5 + 10;

int a[N];

int cnt[N];

int dp[N];

int main() {

    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i ++) {
		int sum = 0;
		int tot = 0;
		
		for (int j = i; j >= 1; j --) {
			sum ^= a[j];
			tot ++;
			
			if (sum == k) {
				cnt[i] = tot;
				break;
			}
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		dp[i] = dp[i - 1];
		if (cnt[i] != 0) {
			dp[i] = max(dp[i], dp[i - cnt[i]] + 1);
		}
	}
	
	cout << dp[n] << "\n";

	return 0;
}

