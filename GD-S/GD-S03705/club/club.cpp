#include <bits/stdc++.h>
using namespace std;
int a[1000000][10];
int a1[1000000];
int b1[1000000];
int dp[40][5][20][20][20];
int n;
map<int,int> mp;
int ans[1000000];
int cnt = 0;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		mp[1] = 0;
		mp[2] = 0;
		mp[3] = 0;
		memset(ans, 0, sizeof(ans));
		cin >> n;
		bool A = 1;
		bool B = 1;
		for(int i = 1;i <= n;i++){
			for(int j = 1;j <= 3;j++){
				cin >> a[i][j];
				if(j != 1 && (a[i][j] != 0)){
					A = 0;
				}
				if(j == 3 && (a[i][j] != 0)){
					B = 0;
				}
			}
		}
		if(A){
			for(int i = 1;i <= n;i++){
				a1[i] = a[i][1];
			}
			sort(a1 + 1, a1 + n + 1, greater<int>());
			int ans = 0;
			for(int i = 1;i <= n / 2;i++){
				ans += a1[i];
			}
			cout <<ans <<endl;
		}else if(n <= 30){
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= 3;j++){
					for(int k = 0 + (j == 1);k <= min(n / 2, i);k++){
						for(int l = 0 + (j == 2);l <= min(n / 2, i);l++){
							for(int o = 0 + (j == 3);o <= min(n / 2, i); o++){
								if(j == 1){
									dp[i][j][k][l][o] = max({dp[i - 1][1][k - 1][l][o], dp[i - 1][2][k - 1][l][o],  dp[i - 1][3][k - 1][l][o]}) + a[i][j];
								}
								if(j == 2){
									dp[i][j][k][l][o] = max(dp[i][j][k][l][o], max({dp[i - 1][1][k][l - 1][o], dp[i - 1][2][k][l - 1][o],  dp[i - 1][3][k][l - 1][o]}) + a[i][j]);
								}
								if(j == 3){
									dp[i][j][k][l][o] = max(dp[i][j][k][l][o], max({dp[i - 1][1][k][l][o - 1], dp[i - 1][2][k][l][o - 1],  dp[i - 1][3][k][l][o - 1]}) + a[i][j]);
								}
							}
						}
					}
				}
			}
			int ans = 0;
			for(int i = 1;i <= n;i++){
				for(int j = 1;j <= 3;j++){
					for(int k = 0;k <= min(n / 2, i);k++){
						for(int l = 0;l <= min(n / 2, i);l++){
							for(int o = 0;o <= min(n / 2, i); o++){
								ans = max(ans, dp[i][j][k][l][o]);
							}
						}
					}
				}
			}
			cout << ans << endl; 
		}
	}
	return 0;
} 
