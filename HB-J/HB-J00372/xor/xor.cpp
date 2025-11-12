#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
int a[500005];
int dp[500005];
int xorn(int l,int r)
{
	int sum=0;
	for(int i=l;i<=r;i++)
		sum^=a[i];
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1]=xorn(1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			if(xorn(j,i)==k)
				dp[i]=max(dp[i-1],max(dp[j-1]+1,dp[i]));
		}
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n];
	return 0;
}
