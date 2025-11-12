#include <bits/stdc++.h>
using namespace std;
#define int long long
int T;
int a[100005], b[100005], c[100005];
int dp[305][305][305];
int n;

void work() {
	cin >> n;
	for(int i = 0; i <= 200; i ++) {
		for(int j = 0; j <= 200; j ++) {
			for(int k = 0; k <= 200; k ++) {
				dp[i][j][k] = 0;
			}
		}
	} 
	for(int i = 1; i <= 1e5; i ++) {
		a[i] = b[i] = c[i] = 0;
	}
	for(int i = 1; i <= n; i ++) {
		cin >> a[i] >> b[i] >> c[i];
	}
	for(int p = 1; p <= n; p ++){
		for(int i = n / 2; i >= 0; i --) {
			for(int j = n / 2; j >= 0; j --) {
				for(int k = n / 2; k >= 0; k --) {
					if(i >= 1) dp[i][j][k] = max(dp[i - 1][j][k] + a[p], dp[i][j][k]);
					if(j >= 1) dp[i][j][k] = max(dp[i][j - 1][k] + b[p], dp[i][j][k]);
					if(k >= 1) dp[i][j][k] = max(dp[i][j][k - 1] + c[p], dp[i][j][k]);
				}
			}
		}		
	}
	cout << dp[n / 2][n / 2][n / 2] << endl;
}

signed main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout); 
	cin >> T;
	while(T --) {
		work();
	} 
	return 0;
}
/* 
-/\__/\ -
(●ω●)-
-v***v---
-\***|---
--\*|----
---V----- 
猫 神 保 佑 


















































































看不见我 
