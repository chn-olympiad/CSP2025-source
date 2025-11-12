#include<bits/stdc++.h>
using namespace std;
bool shu11[30], shu21[30];
int cnt1 = 0, cnt2 = 0, sum = 0;
long long xoor(long long x, long long y) {
	cnt1 = 0, cnt2 = 0, sum = 0;
	memset(shu11, 0, sizeof shu11);
	memset(shu21, 0, sizeof shu21);
	while (x) {
		shu11[++cnt1] = x % 2;
		x /= 2;
	}
	while (y) {
		shu21[++cnt2] = y % 2;
		y /= 2;
	}
	if (cnt1 < cnt2) {
		swap(cnt1, cnt2);
	}
	for (int i = cnt1; i >= 1; i--) {
		if (shu11[i] != shu21[i]) {
			sum += (1 << (i - 1));
		}
	}
	return sum;
}
long long n, k, a[500005], l, r, cnt = 0, a12 = 0;
int ans = 0;
int dp[500005][3][2];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
//	cout<<xoor(xoor(2,1),xoor(0,3));
	cin >> n >> k;
	if (k == 0) {
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
	} else {
		for (int i = 1; i <= n; i++) {
			cin >> a12;
			if (a12 != 0) {
				a[++cnt] = a12;
			}
//			else{
//				cout<<i<<'\n';
//			}
		}
		n = cnt;
	}
	dp[1][0][0] = 0;
	dp[1][2][0] = (a[1] == k ? 1 : 0);
	dp[1][1][0] = 0;
	dp[1][0][1] = 0;
	dp[1][2][1] = a[1];
	dp[1][1][1] = 0;
	for (int i = 2; i <= n; i++) {
		//0 N 1 Y 2 NEW
		dp[i][0][0] = max(dp[i - 1][0][0], max(dp[i - 1][1][0], dp[i - 1][2][0]));

	
		if (xoor(a[i], dp[i - 1][1][1]) == k && dp[i - 1][1][1] != k) {
			if (dp[i][1][0] < dp[i - 1][1][0] + 1)
				dp[i][1][1] = xoor(a[i], dp[i - 1][1][1]) ;
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0] + 1);
		} else {
			if (dp[i][1][0] < dp[i - 1][1][0])
				dp[i][1][1] = xoor(a[i], dp[i - 1][1][1]) ;
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][1][0]);
		}
		if (xoor(a[i], dp[i - 1][2][1]) == k && dp[i - 1][2][1] != k) {
			if (dp[i][1][0] < dp[i - 1][2][0] + 1)
				dp[i][1][1] = xoor(a[i], dp[i - 1][2][1]) ;
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][2][0] + 1);
		} else {
			if (dp[i][1][0] < dp[i - 1][2][0])
				dp[i][1][1] = xoor(a[i], dp[i - 1][2][1]) ;
			dp[i][1][0] = max(dp[i][1][0], dp[i - 1][2][0]);
		}



		if (a[i] == k) {
			dp[i][2][0] = max(dp[i - 1][0][0], max(dp[i - 1][1][0], dp[i - 1][2][0])) + 1;
			dp[i][2][1] = a[i];
		} else {
			dp[i][2][0] = max(dp[i - 1][0][0], max(dp[i - 1][1][0], dp[i - 1][2][0]));
			dp[i][2][1] = a[i];
		}
	}
	cout << max(dp[n][1][0], max(dp[n][0][0], dp[n][2][0]));
//	dfs(0, 0, 0);
//	cout << ans;
	return 0;
}