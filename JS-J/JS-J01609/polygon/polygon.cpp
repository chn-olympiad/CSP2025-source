#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5000,Mod = 998244353;
int n,ans,a[N + 5],dp[N + 5][N + 5];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int mx = a[n];
	dp[0][0] = 1;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= mx;j++){
			dp[i][j] = dp[i - 1][j] % Mod;
			if(j - a[i] >= 0){
			//	cout << dp[i - 1][j - a[i]] << "\n";
				dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % Mod;
			}
		//	cout << i << " " << j << " " << dp[i][j] << "\n";
		}
		dp[i][mx + 1] = dp[i - 1][mx + 1] * 2 % Mod; 
		for(int j = 1;j <= a[i];j++){
			int now = mx - j + 1;
			dp[i][mx + 1] = (dp[i][mx + 1] + dp[i - 1][now]) % Mod;
		}
	//	cout << i << " " << mx + 1 << " " << dp[i][mx + 1] << "\n";
	}
	for(int i = 3;i <= n;i++){
		int t = 0;
		for(int j = a[i] + 1;j <= mx + 1;j++){
			t = (t + dp[i - 1][j]) % Mod;
		}
	//	cout << i << " " << t << "\n";
		ans = (ans + t) % Mod;
	}
	cout << ans << "\n";
	return 0;
}
