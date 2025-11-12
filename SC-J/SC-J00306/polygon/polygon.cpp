#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int dp[5005];
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n, mx = -1;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		if(mx < a[i]) mx = a[i];
	}
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			dp[j] = a[j] + dp[j-1];
		}
	}
	cout << dp[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}