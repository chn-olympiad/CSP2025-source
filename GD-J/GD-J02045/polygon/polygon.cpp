#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+5,mod=998244353;
long long n,a[N],dp[2][10005],ans,mx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[0][0]=1;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		for(int j=10001;j>=0;j--)
		{
			dp[i%2][j]=dp[(i-1)%2][j];
			if(j+a[i]>10000)dp[i%2][10001]=(dp[(i-1)%2][10001]+dp[(i-1)%2][j])%mod;
			else dp[i%2][j+a[i]]=(dp[(i-1)%2][j+a[i]]+dp[(i-1)%2][j])%mod;
		}
		ans=(ans+dp[(i-1)%2][10001])%mod;
		for(int j=2*a[i]+1;j<=10000;j++)
		{
			ans=(ans+dp[(i-1)%2][j-a[i]])%mod;
		}
	}
	cout<<ans;
	return 0;
}
