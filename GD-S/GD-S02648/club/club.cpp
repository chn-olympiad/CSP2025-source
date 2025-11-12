#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;

int a[N][4];
int ca[N][4], cb[N][4], cc[N][4];
int dp[N][4];
int n;

void solve() {
	
	memset(ca, 0, sizeof(ca));
	memset(cb, 0, sizeof(cb));
	memset(cc, 0, sizeof(cc));
	memset(a, 0, sizeof(a));
	memset(dp, 0, sizeof(dp));
	
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= 3; j++) {
			cin >> a[i][j];
		}
	}
	
	dp[1][1] = a[1][1], dp[1][2] = a[1][2], dp[1][3] = a[1][3];
	ca[1][1] = 1;
	cb[1][2] = 1;
	cc[1][3] = 1;
	for(int i = 2; i <= n; i++) {
		int flaga = 0, flagb = 0, flagc = 0;
		if(ca[i-1][1] == n / 2) flaga = 1;
		if(cb[i-1][1] == n / 2) flagb = 1;
		if(cc[i-1][1] == n / 2) flagc = 1;
		ca[i][1] = ca[i-1][1], ca[i][2] = ca[i-1][2], ca[i][3] = ca[i-1][3];
		if(flaga != 1) {
			dp[i][1] = max(dp[i][1], dp[i-1][1] + a[i][1]);
			if(dp[i][1] == dp[i-1][1] + a[i][1]) {
				ca[i][1] = ca[i-1][1] + 1;
				ca[i][2] = ca[i-1][2];
				ca[i][3] = ca[i-1][3];
			}
		} 
		if(flagb != 1) {
			dp[i][1] = max(dp[i][1], dp[i-1][2] + a[i][1]);
			if(dp[i][1] == dp[i-1][2] + a[i][1]) {
				ca[i][1] = cb[i-1][1] + 1;
				ca[i][2] = cb[i-1][2];
				ca[i][3] = cb[i-1][3];
			}
		} 
		if(flagc != 1) {
			dp[i][1] = max(dp[i][1], dp[i-1][3] + a[i][1]);
			if(dp[i][1] == dp[i-1][3] + a[i][1]) {
				ca[i][1] = cc[i-1][1] + 1;
				ca[i][2] = cc[i-1][2];
				ca[i][3] = cc[i-1][3];
			}
		} 
		
		flaga = 0, flagb = 0, flagc = 0;
		if(ca[i-1][2] == n / 2) flaga = 1;
		if(cb[i-1][2] == n / 2) flagb = 1;
		if(cc[i-1][2] == n / 2) flagc = 1;
		cb[i][1] = cb[i-1][1], cb[i][2] = cb[i-1][2], cb[i][3] = cb[i-1][3];
		if(flaga != 1) {
			dp[i][2] = max(dp[i][2], dp[i-1][1] + a[i][2]);
			if(dp[i][2] == dp[i-1][1] + a[i][2]) {
				cb[i][1] = ca[i-1][1];
				cb[i][2] = ca[i-1][2] + 1;
				cb[i][3] = ca[i-1][3];
			}
		} 
		if(flagb != 1) {
			dp[i][2] = max(dp[i][2], dp[i-1][2] + a[i][2]);
			if(dp[i][2] == dp[i-1][2] + a[i][2]) {
				cb[i][1] = cb[i-1][1];
				cb[i][2] = cb[i-1][2] + 1;
				cb[i][3] = cb[i-1][3];
			}
		} 
		if(flagc != 1) {
			dp[i][2] = max(dp[i][2], dp[i-1][3] + a[i][2]);
			if(dp[i][2] == dp[i-1][3] + a[i][2]) {
				cb[i][1] = cc[i-1][1];
				cb[i][2] = cc[i-1][2] + 1;
				cb[i][3] = cc[i-1][3];
			}
		}
		
		flaga = 0, flagb = 0, flagc = 0;
		if(ca[i-1][1] == n / 2) flaga = 1;
		if(cb[i-1][1] == n / 2) flagb = 1;
		if(cc[i-1][1] == n / 2) flagc = 1;
		cc[i][1] = cc[i-1][1], cc[i][2] = cc[i-1][2], cc[i][3] = cc[i-1][3];
		if(flaga != 1) {
			dp[i][3] = max(dp[i][3], dp[i-1][1] + a[i][3]);
			if(dp[i][3] == dp[i-1][1] + a[i][3]) {
				cc[i][1] = ca[i-1][1];
				cc[i][2] = ca[i-1][2];
				cc[i][3] = ca[i-1][3] + 1;
			}
		} 
		if(flagb != 1) {
			dp[i][3] = max(dp[i][3], dp[i-1][2] + a[i][3]);
			if(dp[i][3] == dp[i-1][2] + a[i][3]) {
				cc[i][1] = cb[i-1][1];
				cc[i][2] = cb[i-1][2];
				cc[i][3] = cb[i-1][3] + 1;
			}
		} 
		if(flagc != 1) {
			dp[i][3] = max(dp[i][3], dp[i-1][3] + a[i][3]);
			if(dp[i][3] == dp[i-1][3] + a[i][3]) {
				cc[i][1] = cb[i-1][1];
				cc[i][2] = cb[i-1][2];
				cc[i][3] = cb[i-1][3] + 1;
			}
		}	
	}
	int maxn = max({dp[n][1], dp[n][2], dp[n][3]});
	
	cout << maxn << '\n';
}

signed main() {
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	
	return 0;
}
