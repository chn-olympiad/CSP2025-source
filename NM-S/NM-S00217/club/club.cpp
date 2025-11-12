#include <bits/stdc++.h>
using namespace std;

int t, n, a[100010][4], dp[100010];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin>>t;
	for(int m = 1; m <= t; m++){
		cin>>n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin>>a[i][j];
			}
		}
		dp[1] = a[1][1];
		for(int i = 2; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				for(int k = 1; k <= 3; k++){
					dp[i] = max(dp[i-1]+a[i][j], a[i-1][k]+a[i][j]+dp[i-2]);
				}
			}
		}
		int maxn = 0;
		for(int i = 1; i <= 3; i++){
			if(a[n][i] > maxn) maxn = a[n][i];
		}
		cout<<dp[n] + maxn;
	}
	return 0;
}
