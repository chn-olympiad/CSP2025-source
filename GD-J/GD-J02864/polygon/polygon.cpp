#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e3+10;
int a[N];
int b[N];
ll dp[N][N];
ll ans[N][N];
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<=n;i++)dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5000;j++)
		{
			dp[i][j]=dp[i-1][j-a[i]]+dp[i-1][j]%998244353;
			ans[i][j]=dp[i-1][j-a[i]]%998244353;
		}
	}
	ll sum=0;
	for(int j=3;j<=n;j++)for(int i=a[j]*2+1;i<=5000;i++)sum=(sum+ans[j][i])%998244353;
	cout<<sum%998244353<<endl; 
	return 0;
}
