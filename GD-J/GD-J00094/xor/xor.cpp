#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> a, pre;
ll n, k, cnt = 0;
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	a.resize(n + 1, 0);
	pre.resize(n + 1);
	vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
	for (int i = 1 ; i <= n ; i++) {
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
	}
	if (k == 1) {
		for (auto k : a) {
			cnt+=k;
		}
		cout << cnt;
		return 0;
	}
	/*
	if (k == 0) {
		for (int i = 1 ; i <= n ; i++) {
			if (a[i] == 0) cnt++;
			if (a[i - 1] == 1 && a[i] == 1) {
				a[i - 1] = a[i] = 0;
				cnt++;
			}
		}
		cout << cnt;
		return 0;
	}
	*/
	int i, j;
	for (i = 1 ; i <= n ; i++) {
		if (a[i] == k) {
			cnt++;
			continue;
		}
		for (j = i ; j <= n ; j++) {
			if ((pre[i - 1] ^ pre[j]) == k) {
				cnt++;
				i = j;
				break;
			}
		}
	}
	cout << cnt;
	/*
	for (int i = 1 ; i <= n ; i++) {
		dp[i][i] = dp[i - 1][n];
		for (int j = i ; j <= n ; j++) {
			if (pre[i - 1] ^ pre[j] != k) {
				dp[i][j] = dp[i][j - 1];
			} else {
				dp[i][j] = dp[i][j - 1] + 1;
			}
		}
	}
	cout << dp[n][n]; 
	*/
	return 0;
}
