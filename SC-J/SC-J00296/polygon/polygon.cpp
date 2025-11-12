#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,ans;
int a[200010],h[200010];
int dp[5010][50010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);                     
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		h[i]=h[i-1]+a[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=1;j--)
		{
//			dp[1][a[i]]+=1;
			if(j<3)
				for(int k=h[i];k>=a[i];k--)
					dp[j][k]=(dp[j-1][k-a[i]]+dp[j][k])%mod;
			else
				for(int k=h[i];k>=a[i];k--)
				{
					dp[j][k]=(dp[j-1][k-a[i]]+dp[j][k])%mod;
					if(k>a[i]*2)
					{
						ans=(ans+dp[j-1][k-a[i]])%mod;
//						cout<<a[i]<<" "<<k<<" "<<dp[j][k]<<"\n";
					}
				}
//			cout<<j<<" : ";
//			for(int k=1;k<=h[i];k++)
//				cout<<dp[j][k]<<" ";
//			cout<<"\n";
		}
//	for(int i=1;i<=n;i++)
	cout<<ans<<"\n";
	return 0;
}
//	everything that kills me make mefell alive.
/*
5
1 2 3 4 5
*/