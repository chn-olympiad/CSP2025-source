#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 15, mMAXN = 2e2 + 22, mMAXC = 1e2 + 12, INF = 1e9 + 19;

int n;
int a[MAXN][3];
int tmp[MAXN];
int dp[mMAXN][mMAXC][mMAXC];

void solve() {
	cin >> n;
	bool flag_A = 1;
	int F_ans = 0;
	for(int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1] >> a[i][2];
		F_ans += max({a[i][0], a[i][1], a[i][2]});
		flag_A &= a[i][2] == 0;
	}
	if(flag_A) {
		int ans = 0;
		for(int i = 1; i <= n; i++) {
			ans += a[i][0];
			tmp[i] = a[i][1] - a[i][0];
		}
		sort(tmp + 1, tmp + 1 + n, greater<int>());
		for(int i = 1; i <= n / 2; i++) {
			ans += tmp[i];
		}
		cout << ans << '\n';
	}else if(n <= 200){
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= n / 2; j++) {
				for(int k = 0; k <= n / 2; k++) {
					dp[i][j][k] = -INF;
				}
			}
		}
		dp[0][0][0] = 0;
		for(int i = 1; i <= n; i++) {
			for(int cnt1 = 0; cnt1 <= n / 2; cnt1++) {
				for(int cnt2 = 0; cnt2 <= n / 2; cnt2++) {
					dp[i][cnt1][cnt2] = dp[i - 1][cnt1][cnt2] + a[i][2];
					if(cnt1)dp[i][cnt1][cnt2] = max(dp[i][cnt1][cnt2], dp[i - 1][cnt1 - 1][cnt2] + a[i][0]); 
					if(cnt2)dp[i][cnt1][cnt2] = max(dp[i][cnt1][cnt2], dp[i - 1][cnt1][cnt2 - 1] + a[i][1]);
				}
			}
		}
		int ans = 0;
		for(int i = 0; i <= n / 2; i++) {
			for(int j = 0; j <= n / 2 && j + i <= n; j++) {
				if(n / 2 < n - i - j)continue;
				ans = max(ans, dp[n][i][j]);
//				cout << i << ' ' << j << ' ' << dp[n][i][j] << '\n';
			}
		}
		cout << ans << '\n';
	}else{
		cout << F_ans << '\n';
	}
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int T;
	for(cin >> T; T--; solve());
	return 0;
}
