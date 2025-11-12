#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001],b[100001],c[100001],dp[201][101][101],ans;
bool cmp(int w,int e)
{
	return w>e;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int q=1;q<=t;q++)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
		bool pd=1;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=0||c[i]!=0)
			{
				pd=0;
				break;
			}
		}
		if(pd)
		{
			long long cnt=0;
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++)
			{
				cnt+=a[i];
			}
			cout<<cnt<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=min(i,n/2);j++) 
			{
				for(int k=0;k<=min(i-j,n/2);k++)
				{
					int q=i-j-k;
					if(q<=n/2)
					{	
						if(j>0) dp[i][j][k]=max(dp[i-1][j-1][k]+a[i],dp[i][j][k]);
						if(k>0) dp[i][j][k]=max(dp[i-1][j][k-1]+b[i],dp[i][j][k]);
						if(q>0) dp[i][j][k]=max(dp[i-1][j][k]+c[i],dp[i][j][k]);
						ans=max(dp[i][j][k],ans);
					}	
				} 
			}
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=n/2;j++)
				for(int k=0;k<=n/2;k++) dp[i][j][k]=0;
	}
	return 0;
}