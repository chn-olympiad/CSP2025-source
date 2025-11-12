#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[500005],dp[500005],xr[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);	
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		xr[i]=xr[i-1]^a[i];
	}//xr[r]^xr[l-1]=[l,r]区间异或和 
	for(int i=1;i<=n;i++)
	{
		int j=i;
		while(j>0)
		{
			if((xr[i]^xr[j-1])==k)break;
			j--;
		}
		if(j>0)dp[i]=max(dp[j-1]+1,dp[i-1]);
		else dp[i]=dp[i-1];
	//	cout<<r<<" "<<l<<" "<<dp[r]<<"\n";
	}
	cout<<dp[n];
	return 0;
}
