#include<bits/stdc++.h>
using namespace std;
long long n,k,h=0,dp[500005],z=0,a[500005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=h;j--)
		{
			dp[i]=dp[i]^a[j];
			if(dp[i]==k)
			{
				z++;
				h=i+1;
				break;
			}
		}
	}
	cout<<z;
	return 0;
}
