#include<bits/stdc++.h>
using namespace std;			
int n;
int ans=0;
int a0[1005][5];
int tmpa0[100005];
int dp0[200][106][106][106];
int dp1[205][105][105];
bool cmp(int x,int y)
{
	return x>y;
}
void dfs(int x,int a,int b,int c,int sum)
{
	if(x==n+1)
	{
		ans=max(ans,sum);
	}
	if(a+1<=n/2)
	{
		dfs(x+1,a+1,b,c,sum+a0[x][1]);
	}
	if(b+1<=n/2)
	{
		dfs(x+1,a,b+1,c,sum+a0[x][2]);
	}
	if(c+1<=n/2)
	{
		dfs(x+1,a,b,c+1,sum+a0[x][3]);
	}

}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
		{
			ans=0;
			cin>>n;
			// cout<<n<<endl;
			int allarea=1;
			int all3shiling=1;
			for(int i=1;i<=n;i++)
			{
				cin>>a0[i][1]>>a0[i][2]>>a0[i][3];	
				if(a0[i][3]!=0)all3shiling=0;
				if(a0[i][2]!=0||a0[i][3]!=0)
				{
					allarea=0;
				}
			}
			// if(n<=10){
			// 	dfs(1,0,0,0,0);
			// 	cout<<ans<<endl;
			// }
			if(allarea)
			{
				for(int i=1;i<=n;i++)
				{
					tmpa0[i]=a0[i][1];
				}
				sort(tmpa0+1,tmpa0+n+1,cmp);
				int ans=0;
				for(int i=1;i<=n/2;i++)ans+=tmpa0[i];
				cout<<ans<<endl;
			}
			if(all3shiling)//特殊性质B,这一部分也是对的
			{
				memset(dp1,0,sizeof(dp1));
				int ans1=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<=min(i,n/2);j++)
					{
						for(int k=0;k<=min(i,n/2);k++)
						{
							// for(int l=0;l<=min(i,n/2);l++)
							// {
								// cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<n/2<<endl;
								if(j>=1)dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j-1][k]+a0[i][1]);
								if(k>=1)dp1[i][j][k]=max(dp1[i][j][k],dp1[i-1][j][k-1]+a0[i][2]);

								// if(l>=1)dp0[i][j][k][l]=max(dp0[i][j][k][l],dp0[i-1][j][k][l-1]+a0[i][3]);
								ans1=max(ans1,dp1[i][j][k]);
								// cout<<"debug "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<" "<<dp0[i][j][k][l]<<endl;

							// }
						}
					}
				}
				cout<<ans1<<endl;
			}
			else if(n<=200)//这一部分测试通过
			{
				memset(dp0,0,sizeof(dp0));
				int ans0=0;
				for(int i=1;i<=n;i++)
				{
					for(int j=0;j<=min(i,n/2);j++)
					{
						for(int k=0;k<=min(i,n/2)&&j+k<=i;k++)
						{
							for(int l=0;l<=min(i,n/2)&&j+k+l<=i;l++)
							{
								// cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<n/2<<endl;
								if(j>=1)dp0[i][j][k][l]=max(dp0[i][j][k][l],dp0[i-1][j-1][k][l]+a0[i][1]);
								if(k>=1)dp0[i][j][k][l]=max(dp0[i][j][k][l],dp0[i-1][j][k-1][l]+a0[i][2]);

								if(l>=1)dp0[i][j][k][l]=max(dp0[i][j][k][l],dp0[i-1][j][k][l-1]+a0[i][3]);
								ans0=max(ans0,dp0[i][j][k][l]);
								// cout<<"debug "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<" "<<dp0[i][j][k][l]<<endl;

							}
						}
					}
				}
				cout<<ans0<<endl;
			}
			
			// if(n<=200)
			// {

			// }
		}
	return 0;
}