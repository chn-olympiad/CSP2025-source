#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int n;
int s[maxn][maxn],tot[maxn][maxn][maxn],dp[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for (int i = 1;i <= n;i++){
			for (int j = 1;j <= 3;j++){
				cin >> s[i][j];	
			}
		}
	}
	if(n < 201){
		int maxs =  n/2;
		int sco[maxn][4];
		int s1  = 0,s2 = 0,s3 = 0;
		for(int i = 1; i <= n; i++){
			for (int j = 1; j <= n;j++){
				int pos = 0;
				for (int k = 1; k <= 3;k++){
					if (tot[i-1][j][k] < maxn && dp[i-1][k] < dp[i][k] + s[i][j]){
						dp[i][j] = dp[i-1][k] + s[i][j];
						pos = k;
					}
				}	
				for (int k = 1;k <= 3;k++){
					if(pos == k) tot[i][j][k] = tot[i-1][j][k+1];
					else tot[i][j][k] = tot[i-1][j][k];
				}
			}
		}
		int ans = dp[n][1];
		cout << ans;
	}
	return 0;
}