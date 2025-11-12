#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],sum[N],dp[N];
int n,k;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int b=0,b1=0,b0=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]<=1) b++;
		if(a[i]==1) b1++;
		if(a[i]==0) b0++;
		sum[i]=sum[i-1]^a[i];
	}
	if(b==n&&k<=1)
	{
		if(k==1) cout<<b1;
		if(k==0) cout<<b0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int nsm=0;
		for(int j=i;j>=1;j--)
		{
			nsm^=a[j];
			if(nsm==k)
			{
				dp[i]=max(dp[i],dp[j-1]+1);
				break; 
			}
		}
		if(dp[i]==0) dp[i]=dp[i-1];
	}
	cout<<dp[n];
	return 0;
}