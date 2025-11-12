#include<bits/stdc++.h>
using namespace std;

int a[1005], dp[1005][1005];
bool tf[1005][1005];

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] == k)
			dp[i][i] = 1;
		else
			dp[i][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		int num = a[i];
		if(num == k){
			tf[i][i] = 1;
		}else{
			tf[i][i] = 0;
		}
		for(int j = i + 1; j <= n; j++){
			num ^= a[j];
			if(num == k){
				tf[i][j] = 1;
			}else{
				tf[i][j] = 0;
			}
		}
	}
	for(int l = 0; l < n; l++){
		for(int j = 1; j <= n - l; j++){
			dp[j][j + l] = int(tf[j][j + l]);
			for(int k = j; k < j + l; k++){
				dp[j][j + l] = max(dp[j][j + l], dp[j][k] + dp[k + 1][j + l]);
			}
		}
	}
	cout << dp[1][n];
	return 0;
}
