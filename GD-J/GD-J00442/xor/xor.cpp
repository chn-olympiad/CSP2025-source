#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
int a[500005];
int s[500005];
int dp[10001][10001];
int main() {
//	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i - 1] ^ a[i];
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] == k) dp[i][i] = 1;
	}
	for(int len = 2; len <= n; len++) {
		for(int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
//			cout << r << " ";
			for(int m = l; m < r; m++) {
				int val_l = s[m] ^ s[l - 1];
				int val_r = s[r] ^ s[m];
				if(val_l == k && dp[l][m] == 0) dp[l][m] = 1;
				if(val_r == k && dp[m + 1][r] == 0) dp[m + 1][r] = 1;
				int val = s[r] ^ s[l - 1];
				dp[l][r] = max(val == k ? 1 : 0, dp[l][m] + dp[m + 1][r]);
			}
		}
	}
	cout << dp[1][n];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
