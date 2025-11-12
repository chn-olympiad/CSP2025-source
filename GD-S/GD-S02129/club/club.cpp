#include<bits/stdc++.h>
using namespace std;
long long e,n,t[1000005],sum,dp[5][100005];
struct f{
	long long x,y,z,k;
}a[1000005],b[1000005],c[1000005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>e;
	while(e--)
	{
		long long tx=0,ty=0,tz=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].z);
		}
		for(int i=1;i<=n;i++)
		{
			if(tx<n/2)dp[1][i]=max(dp[1][i-1],max(dp[2][i-1],dp[3][i-1]))+a[i].x,tx++;
			else dp[1][i]=max(dp[2][i-1],dp[3][i-1])+a[i].x;
			
			
			if(ty<n/2)dp[2][i]=max(dp[1][i-1],max(dp[2][i-1],dp[3][i-1]))+a[i].y,ty++;
			else dp[2][i]=max(dp[1][i-1],dp[3][i-1])+a[i].y;
			
			if(tz<n/2)dp[3][i]=max(dp[1][i-1],max(dp[2][i-1],dp[3][i-1]))+a[i].z,tz++;
			else dp[3][i]=max(dp[2][i-1],dp[1][i-1])+a[i].z;
		}
		cout<<max(dp[1][n],max(dp[2][n],dp[3][n]))<<endl;
	}
	return 0;
} 
