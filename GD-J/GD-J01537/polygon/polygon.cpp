#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[5005], dp[5005][5005], sum=1;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) dp[i][1]=i, dp[i][2]=i*(i-1)/2;
	for(int i=3; i<=n; i++){
		for(int j=3; j<=i; j++){
			dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%998244353;
			if(i==n) sum=(sum+dp[i][j])%998244353;
		}
	}
	cout << sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
