#include<bits/stdc++.h>
using namespace std;
const int N = 100005; 
int w[N][3], c[3], sum[N], dp[N][3], a[6];
int t, n, maxx;
int main(){
	cin >> t;
	for (int j = 1; j <= t; j++){
		cin >> n;
		for(int i = 1; i <= n; i++){
			for (int k = 0; k <= 2; k++){
				cin >> w[i][k];
			}
		}
		for (int i = 1; i <= n; i++){
			for (int k = 0; k <= 2; k++){
				dp[i][k] = 0;
			}
		}
		for (int i = 0; i <= 2; i++){
			dp[1][i] = w[1][i];
			sum[i]++;
		}
		for (int i = 2; i <= n; i++){
			for (int k = 0; k <= 2; k++){
				if(sum[k] <= n / 2){
					dp[i][k] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]) + w[i][k];
					sum[k]++;
				}
				maxx = max(dp[i][k], maxx);
			}
		}
		cout << maxx;	
	}
	return 0;
}
