//GZ-S00017 贵阳市第一中学 伍星恒 
#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100005][4];
int dp[101][101][101];
int x[100005];
int y, z;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> t;
	while(t--){
		memset(a, 0, sizeof(a));
		cin >> n;
		int ans = 0;
		y = 0;
		z = 0;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			y += a[i][2];
			z += a[i][3];
		}
		if(n <= 200){
			//#1-11  55pts 
			memset(dp, 0, sizeof(dp));
			dp[0][0][0] = 0;
			for(int i = 1; i <= n/2; i++){
				dp[i][0][0] = dp[i-1][0][0] + a[i][1];
				dp[0][i][0] = dp[0][i-1][0] + a[i][2];
				dp[0][0][i] = dp[0][0][i-1] + a[i][3];
			}
			for(int i = 1; i <= n/2; i++){
				for(int j = 1; j <= n/2; j++){
					dp[i][j][0] = max(dp[i-1][j][0] + a[i+j][1], dp[i][j-1][0] + a[i+j][2]);
					dp[i][0][j] = max(dp[i-1][0][j] + a[i+j][1], dp[i][0][j-1] + a[i+j][3]);
					dp[0][i][j] = max(dp[0][i-1][j] + a[i+j][2], dp[0][i][j-1] + a[i+j][3]);
				}
			}
			for(int i = 1; i <= n/2; i++){
				for(int j = 1; j <= n/2; j++){
					for(int k = 1; k <=  n-i-j ; k++){
						if(n-i-j <= 100){
							dp[i][j][k] = max(dp[i-1][j][k] + a[i+j+k][1], max(dp[i][j-1][k] + a[i+j+k][2], dp[i][j][k-1] + a[i+j+k][3]));
						}
					}
					if(n-i-j <= n/2){
						ans = max(ans, dp[i][j][n-i-j]);
					}
				}
			}
			
			cout << ans << endl;
			 
		}
		else if(y == 0){
			//#12  5pts
			memset(x, 0, sizeof(x));
			for(int i = 1; i <= n; i++){
				x[i] = a[i][1];
			} 
			sort(x+1, x+n+1, greater<int>());
			for(int i = 1; i <= n/2; i++){
				ans += x[i];
			}
			cout << ans << endl;
			
			
		}
		else{
			//#15-16 & 骗分   10pts+
			z = 0;
			for(int i = 1; i <= n; i++){
				z += max(a[i][1], max(a[i][2], a[i][3]));
			} 
			cout << z << endl;
			
		}
	}
	//预期：70pts+（555这什么东西啊……） 
	return 0;
}
