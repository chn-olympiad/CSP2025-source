#include<bits/stdc++.h>
using namespace std;
const int Maxn = 5005;
const int maxx = Maxn*8;
long long n, dp[Maxn][maxx],ans, a[Maxn];
int main()
{
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int i = 1;i<=n;i++){
		for(int j = 0;j<=maxx;j++){
			
			dp[i][j]=dp[i-1][j];
			if(j<a[i])dp[i][j]++;
			if(j>=a[i])dp[i][j]+=dp[i-1][j-a[i]];
			else dp[i][j]+=dp[i-1][0];
			dp[i][j]%=998244353;
			if(dp[i][j]==0)break;
		}
	}
	
	for(int i = 1;i<n;i++){
		ans+=(dp[i][2*a[i]])%998244353;
		ans%=998244353;
	}
	ans+=(dp[n][2*a[n]]%998244353);
	ans%=998244353;
	cout<<ans;
	return 0;	
} 
