#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,a1[N],a2[N],a3[N],dp[202][101][101][101];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n;
		bool oka=true;
		for(int i=1;i<=n;i++)
		{
			cin>>a1[i]>>a2[i]>>a3[i];
			if(a2[i]!=0||a3[i]!=0)
			{
				oka=false;
			}
		}
		if(oka)
		{
			sort(a1+1,a1+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++)
			{
				ans+=a1[i];
			}
			cout<<ans<<endl;
		}
		else
		{
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j1=0;j1<=i&&j1<=n/2;j1++)
				{
					for(int j2=0;j1+j2<=i&&j2<=n/2;j2++)
					{
						for(int j3=0;j1+j2+j3<=i&&j3<=n/2;j3++)
						{
							if(j1>0)
							{
								dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1-1][j2][j3]+a1[i]);
							}
							if(j2>0)
							{
								dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2-1][j3]+a2[i]);
							}
							if(j3>0)
							{
								dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2][j3-1]+a3[i]);
							}
							ans=max(ans,dp[i][j1][j2][j3]);
						}
					}
				}
			}
			cout<<ans<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j1=0;j1<=i&&j1<=n/2;j1++)
				{
					for(int j2=0;j1+j2<=i&&j2<=n/2;j2++)
					{
						for(int j3=0;j1+j2+j3<=i&&j3<=n/2;j3++)
						{
							dp[i][j1][j2][j3]=0;
						}
					}
				}
			}
		}
	}
	return 0;
 } 
