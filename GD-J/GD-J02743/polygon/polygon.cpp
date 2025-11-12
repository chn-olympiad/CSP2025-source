#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 20;
long long modn = 998244353ll;
long long n,dp[3][N],a[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	long long mx = 0ll-1ll;
	for(int i = 1;i <= n;i++) scanf("%lld",&a[i]);
	for(int i = 1;i <= n;i++){
		mx = max(mx,a[i]);
	}
	for(int i = 1;i <= 2;i++){
		for(int j = 0;j <= mx + 1;j++) dp[i][j] = 0ll;
	}
	sort(a+1,a+1+n);
	dp[1][0] = 1ll,dp[1][a[1]] = 1ll;
	long long ans = 0ll;
	for(int i = 2;i <= n;i++){
		for(int j = 0;j <= mx + 1;j++){
			if(j > a[i]) ans = (ans + dp[1][j]) % modn;
			dp[2][j] = (dp[2][j] + dp[1][j]) % modn;
			if(j + a[i] > mx) dp[2][mx + 1] = (dp[2][mx + 1] + dp[1][j]) % modn;
			else dp[2][j + a[i]] = (dp[2][j + a[i]] + dp[1][j]) % modn;
		}
		for(int j = 0;j <= mx + 1;j++){
			
			dp[1][j] = dp[2][j];
			dp[2][j] -= dp[2][j];
			
		}
		
	}
	
	cout << ans;
	return 0;
}
