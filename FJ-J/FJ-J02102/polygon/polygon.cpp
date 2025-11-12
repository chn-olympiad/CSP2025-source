#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5010;
const ll mod=998244353;
ll dp[N][N],a[N],ans=0;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=5000;j++)
		{
			dp[i][j]=(a[i]>j);
			dp[i][j]=(dp[i][j]+dp[i-1][max(0*1ll,j-a[i])]+dp[i-1][j])%mod;
		}
	}
	for(int i=1;i<=n;i++)ans=(ans+dp[i-1][a[i]])%mod;
	cout<<ans;
	return 0;
}
