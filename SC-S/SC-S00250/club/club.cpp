#include<bits/stdc++.h>
using namespace std;
const int N = 300;
int t, n, a[N][5];
long long dp[N][N][N], a1, b1, c1, ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t --){
		cin >> n;
		memset(dp, 0, sizeof dp);
		ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= 3;j ++){
				cin >> a[i][j];
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int i1 = 0;i1 <= min(i, n/2);i1 ++){
				for(int i2 = 0;i2 <= min(i - i1, n/2);i2++){
					if(i - i1 - i2 > n/2)continue;
					a1 = 0, b1 = 0, c1 = 0;
					if(i1 != 0)a1 = dp[i-1][i1-1][i2] + a[i][1];
					if(i2 != 0)b1 = dp[i-1][i1][i2-1] + a[i][2];
					if(i - i1 - i2 != 0)c1 = dp[i-1][i1][i2] + a[i][3];
					dp[i][i1][i2] = max(a1, max(b1, c1));
					ans = max(ans, dp[i][i1][i2]);
				}
			}			
		}
		cout << ans << "\n";
	} 
	return 0;
}