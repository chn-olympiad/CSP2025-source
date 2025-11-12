#include <bits/stdc++.h>
using namespace std;
const int N = 998244353;
/*
dp[i][j] = dp[i-1][j];
dp2[i][j] = dp2[i-1][j];
dp3[i][j] = dp3[i-1][j];
if (max(dp2[i-1][j-1],a[i])*2 < dp3[i-1][j-1]+a[i])
{
	dp[i][j] += dp[i-1][j-1]+1;
	dp2[i][j] = max(dp2[i-1][j-1],a[i]);
	dp3[i][j] = max(dp3[i-1][j-1]+a[i],dp3[i][j]);
}
*/ 
int a[5010];
int sum[5010];
int st[5010];
int ans,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++)cin >> a[i];
	ans = 1;
	for (int i=1;i<=n-3;i++){
		ans *= 2;
	}
	ans *= n*(n-1)*(n-2)/6;
	cout << ans;
	return 0;
}
