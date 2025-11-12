#include <bits/stdc++.h>
using namespace std;
const int N = 40, M = 2e2 + 10, O = 1e5 + 10;
int n, dp[N][N][N][N], p[M][M][M], a[O][3], T, c[O];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
			c[i] = a[1];
		}
		if(n <= 30){
			for(int i = 0; i <= n; i++)
				for(int j = 0; j <= n / 2; j++)
					for(int k = 0; k <= n / 2; k++)
						for(int l = 0; l <= n / 2; l++)
							dp[i][j][k][l] = -2e9;
			dp[0][0][0][0] = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= n / 2; j++){
					for(int k = 0; k <= n / 2; k++){
						for(int l = 0; l <= n / 2; l++){
							dp[i][j + 1][k][l] = max(dp[i][j + 1][k][l], dp[i - 1][j][k][l] + a[i][1]);
							dp[i][j][k + 1][l] = max(dp[i][j][k + 1][l], dp[i - 1][j][k][l] + a[i][2]);
							dp[i][j][k][l + 1] = max(dp[i][j][k][l + 1], dp[i - 1][j][k][l] + a[i][3]);
						}
					}
				}
			}
			int ans = 0;
			for(int i = 0; i <= n / 2; i++)
				for(int j = 0; j <= n / 2; j++)
					for(int k = 0; k <= n / 2; k++)
						ans = max(ans, dp[n][i][j][k]);
			cout << ans << '\n';
		}else if(n <= 200){
			for(int i = 0; i <= n; i++)
				for(int j = 0; j <= n / 2; j++)
					for(int k = 0; k <= n / 2; k++)
							p[i][j][k] = -1e9;
			p[0][0][0] = 0;
			for(int i = 1; i <= n; i++){
				for(int j = 0; j <= n / 2; j++){
					for(int k = 0; k <= n / 2; k++){
							p[i][j + 1][k] = max(p[i][j + 1][k], p[i - 1][j][k] + a[i][1]);
							p[i][j][k + 1] = max(p[i][j][k + 1], p[i - 1][j][k] + a[i][2]);
					}
				}
			}
			int ans = 0;
			for(int i = 0; i <= n / 2; i++)
				for(int j = 0; j <= n / 2; j++)
						ans = max(ans, p[n][i][j]);
			cout << ans << '\n';
		}else{
			sort(c + 1, c + n + 1);
			int ans = 0;
			for(int i = 1; i <= n / 2; i++) ans += c[i];
			cout << ans << '\n';
		}
	}	
	return 0;
}
