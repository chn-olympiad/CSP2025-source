#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,p=998244353;
long long a[N],sum[N],pre[N],dp[N][N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{    
	    dp[1][0]=1;
		for(int j=0;j<=5005;j++)
		{
			dp[i][j]=dp[i-1][j]+(j-a[i]>=0?dp[i-1][j-a[i]]:dp[i-1][0]+1);
			dp[i][j]%=p;
		}
	}
	long long ans=0;
	for(int i=3;i<=n;i++)
	{
		ans+=dp[i-1][a[i]];
		ans%=p;
	}
	cout<<ans;
	return 0;
}
