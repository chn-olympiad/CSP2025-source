#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[5010];
long long dp[5010][5010];
const long long m = 998244353;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j <= 5001; j++){
			dp[i][j] += dp[i - 1][j];
			if (j + a[i] > 5000){
				dp[i][5001] += dp[i - 1][j];
				dp[i][5001] %= m;
			}else{
				dp[i][j + a[i]] += dp[i - 1][j];
				dp[i][j + a[i]] %= m;
			}
		}
	}
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		for (int j = a[i] + 1; j <= 5001; j++){
			sum += dp[i - 1][j];
			sum %= m;
		}
	}
	cout << sum;
	return 0;
} 
