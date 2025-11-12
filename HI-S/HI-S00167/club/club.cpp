#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N][3];
int dp[N][3]; 
int f[N];
int b[N];
bool cmp(int a, int b) {
	return a > b;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		memset(a, 0, sizeof(a));
		memset(dp, 0, sizeof(dp));
		memset(f, 0, sizeof(f));
		int n;
		cin >> n;
		long long ans = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j]; 
			}
		}
		bool flag = true, flag2 = true;
		for (int i = 1; i <= n; i++) {
			if(a[i][2] != 0) flag = false;
			if(a[i][3] != 0) flag2 = false;
		}
		if(flag && flag2) {
			for(int i = 1; i <= n; i++)  b[i] = a[i][1];
			sort(b + 1, b + n + 1, cmp);
			long long ans = 0;
			for(int i = 1; i <= n / 2; i++) {
				ans += b[i];
			}
			cout << ans << endl;
		    continue;
		}
		dp[1][1] = a[1][1];
		dp[1][2] = a[1][2];
		dp[1][3] = a[1][3];
		f[1] = max(max(dp[1][1], dp[1][2]), dp[1][3]);
		for (int i = 2; i <= n; i++) {
			dp[i][1] = max(max(dp[i - 1][1] + a[i][1], dp[i - 1][2] + a[i][1]), dp[i - 1][3] + a[i][1]);
			dp[i][2] = max(max(dp[i - 1][1] + a[i][2], dp[i - 1][2] + a[i][2]), dp[i - 1][3] + a[i][2]);
			dp[i][3] = max(max(dp[i - 1][1] + a[i][3], dp[i - 1][2] + a[i][3]), dp[i - 1][3] + a[i][3]);
			f[i] = max(max(dp[i][1], dp[i][2]), dp[i][3]);
		} 
		ans = f[n];
		cout << ans << endl;
	}
	return 0;
}
