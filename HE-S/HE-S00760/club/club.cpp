#include<bits/stdc++.h>
using namespace std;
long long T,n,a[2010][10],dp[110][110][110],ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int x=1;x<=T;x++)
	{
		ans=0;
		memset(a,sizeof(a),0);
		memset(dp,sizeof(dp),0);
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		for(int i=0;i<=n/2;i++)
		{
			for(int j=0;j<=n/2;j++)
			{
				for(int k=0;k<=min(n-i-j,n/2);k++)
				{
					dp[i][j][k]=max((i>0?dp[i-1][j][k]+a[i+j+k][1]:0),max((j>0?dp[i][j-1][k]+a[i+j+k][2]:0),(k>0?dp[i][j][k-1]+a[i+j+k][3]:0)));
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
