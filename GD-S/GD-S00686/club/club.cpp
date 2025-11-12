#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e2 + 10;
int n, w[maxn][4];

int dp[maxn][maxn/2][maxn/2][maxn/2], mxdp[maxn];


void solve(){
	memset(dp, 0, sizeof(dp));
	memset(mxdp, 0, sizeof(mxdp));
	cin >> n;
	for (int i=1; i<=n; i++){
		cin >> w[i][1] >> w[i][2] >> w[i][3];
	}
	for (int i=1; i<=n; i++){
		//把i拆成三部分 
		for (int a=0; a<=i&&a<=n/2; a++){
			for (int b=0; b<=i-a&&b<=n/2; b++){
				int c = i-a-b;
				if (c>n/2) continue;
				if (a+b+c<=i-1) dp[i][a][b][c] = dp[i-1][a][b][c];
				if (a>=1) dp[i][a][b][c] = max(dp[i][a][b][c], dp[i-1][a-1][b][c] + w[i][1]);
				if (b>=1) dp[i][a][b][c] = max(dp[i][a][b][c], dp[i-1][a][b-1][c] + w[i][2]);
				if (c>=1) dp[i][a][b][c] = max(dp[i][a][b][c], dp[i-1][a][b][c-1] + w[i][3]);
				mxdp[i] = max(mxdp[i], dp[i][a][b][c]);
			}
		}
	}
//	int mx = 0, idx = 0;
//	for (int i=1; i<=3; i++){
//		if (dp[n][i].val > mx){
//			mx = dp[n][i].val;
//			idx = i;
//		} 
//	}
//	cout << dp[3][2].cnt[2] << '\n';
	cout << mxdp[n] << '\n';
//	for (int a=0; a<=n; a++){
//		for (int b=0; b<=n-a; b++){
//			int c = n-a-b;
//			cout << a << " " << b << " " << c << " : " << dp[n][a][b][c] << '\n'; 
//		} 
//	}
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}
