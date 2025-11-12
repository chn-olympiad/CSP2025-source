#include<bits/stdc++.h>
using namespace std;

int t;
int dp[100010][3];
int dx[100010];
int ans, mx;

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	int n;
	while(t--) {
		cin >> n;
		int k = n/2;
		ans = 0;
		for(int i=0; i<n; i++) {
			mx = -1;
			for(int j=0; j<3; j++) {
				cin >> dp[i][j];
				if(dp[i][j] > mx) {
					mx = dp[i][j];
					dx[i] = j;
				}
			}
		}
		int ac=0, bc=0, cc=0;
		for(int i=0; i<n; i++) {
			if(dx[i]==0)	ac++;
			if(dx[i]==1)	bc++;
			if(dx[i]==2)	cc++;
		}
		if(ac<=k&&bc<=k&&cc<=k) {
			for(int i=0; i<n; i++) {
				ans += dp[i][dx[i]];
			}
			cout << ans << endl;
			continue;
		}
		if(bc > k) {
			dx[0] == 1? bc=1 : bc=0;
			for(int i=1; i<n; i++) {
				if(dx[i] != 1) {
					dp[i][dx[i]] += dp[i-1][dx[i-1]];
					continue;
				}
				if(bc < k) {
					if(dx[i+1] != 1) {
						dp[i][1]+=dp[i-1][dx[i-1]];
						bc++;
					} else {
						if(dp[i+1][1]>dp[i][1]) {
							dp[i][dx[i]] = max(dp[i][0],dp[i][2]);
							dp[i][dx[1]]+=dp[i-1][dx[i-1]];
						} else {
							dp[i][1]+=dp[i-1][dx[i-1]];
							bc++;
						}
					}
				} else {
					int f, l;
					if(dp[i][0]>dp[i][2]) f=0;
					else f=2;
					int cnt = 0;
					while(dx[cnt]!=1) {
						cnt++;
					}
					if(dp[cnt][0]>dp[cnt][2])	l=0;
					else	l=2;
					int r = dp[i][dx[i]];
					dp[i][dx[i]] = max(dp[i][1]+dp[i-1][dx[i-1]]-dp[cnt][1], dp[i][f]+dp[i-1][dx[i-1]]);
					dp[i][dx[i]] = max(dp[i][dx[i]], r+dp[i-1][dx[i-1]]-dp[cnt][1]+dp[cnt][l]);
					if(f == 0)	ac++;
					else	cc++;
				}
			}
			cout << dp[n-1][dx[n-1]] << endl;
			continue;
		}
		if(ac > k) {
			dx[0] == 0? ac=1 : ac=0;
			for(int i=1; i<n; i++) {
				if(dx[i] != 0) {
					dp[i][dx[i]] += dp[i-1][dx[i-1]];
					continue;
				}
				if(ac < k) {
					if(dx[i+1] != 0) {
						dp[i][0]+=dp[i-1][dx[i-1]];
						ac++;
					} else {
						if(dp[i+1][0]>dp[i][0]) {
							dp[i][dx[i]] = max(dp[i][1],dp[i][2]);
							dp[i][dx[i]]+=dp[i-1][dx[i-1]];
						} else {
							dp[i][0]+=dp[i-1][dx[i-1]];
							ac++;
						}
					}
				} else {
					int f, l;
					if(dp[i][1]>dp[i][2]) f=1;
					else f=2;
					int cnt = 0;
					while(dx[cnt]!=0) {
						cnt++;
					}
					if(dp[cnt][1]>dp[cnt][2])	l=1;
					else	l=2;
					int r = dp[i][dx[i]];
					dp[i][dx[i]] = max(dp[i][0]+dp[i-1][dx[i-1]]-dp[cnt][0], dp[i][f]+dp[i-1][dx[i-1]]);
					dp[i][dx[i]] = max(dp[i][dx[i]], r+dp[i-1][dx[i-1]]-dp[cnt][0]+dp[cnt][l]);
					if(f == 1)	bc++;
					else	cc++;
				}
			}
			cout << dp[n-1][dx[n-1]] << endl;
			continue;
		}
		if(cc > k) {
			dx[0] == 0? cc=1 : cc=0;
			for(int i=1; i<n; i++) {
				if(dx[i] != 2) {
					dp[i][dx[i]] += dp[i-1][dx[i-1]];
					continue;
				}
				if(cc < k) {
					if(dx[i+1] != 2) {
						dp[i][2]+=dp[i-1][dx[i-1]];
						cc++;
					} else {
						if(dp[i+1][2]>dp[i][2]) {
							dp[i][dx[i]] = max(dp[i][1],dp[i][0]);
							dp[i][dx[i]]+=dp[i-1][dx[i-1]];
						} else {
							dp[i][2]+=dp[i-1][dx[i-1]];
							cc++;
						}
					}
				} else {
					int f, l;
					if(dp[i][1]>dp[i][0]) f=1;
					else f=0;
					int cnt = 0;
					while(dx[cnt]!=2) {
						cnt++;
					}
					if(dp[cnt][0] > dp[cnt][1])	l = 0;
					else	l = 1;
					int r = dp[i][dx[i]];
					dp[i][dx[i]] = max(dp[i][2]+dp[i-1][dx[i-1]]-dp[cnt][2], dp[i][f]+dp[i-1][dx[i-1]]);
					dp[i][dx[i]] = max(dp[i][dx[i]], r+dp[i-1][dx[i-1]]-dp[cnt][2]+dp[cnt][l]);
					if(f == 1)	bc++;
					else	ac++;
				}
			}
			cout << dp[n-1][dx[n-1]] << endl;
			continue;
		}
	}
	return 0;
}
