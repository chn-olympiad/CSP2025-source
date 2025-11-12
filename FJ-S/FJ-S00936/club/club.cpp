#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,z,dp[210][210][210],ans;
struct node
{
	long long x,y,z;
}a[210],b[200000];
bool cmp(node i,node j)
{
	return i.x-j.x>i.y-j.y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie();
	cout.tie();
	cin>>t;
	while(t--)	
	{
		ans=-1;
		cin>>n;
		if(n<=200)
		{
			for(long long i=1;i<=n;i++)
			{
				cin>>a[i].x>>a[i].y>>a[i].z;
			}
			for(long long i=0;i<=n/2;i++)
			{
				for(long long j=0;j<=n/2;j++)
				{
					for(long long k=0;k<=n/2;k++)
					{
						dp[i][j][k]=0;
					}
				}
			}
			for(long long l=1;l<=n;l++)
			{
				for(long long i=0;i<=n/2;i++)
				{
					for(long long j=0;j<=n/2;j++)
					{
						long long k=l-i-j;
						if(k>=0&&k<=n/2)
						{
							if(i)dp[i][j][k]=max(dp[i-1][j][k]+a[l].x,dp[i][j][k]);
							if(j)dp[i][j][k]=max(dp[i][j-1][k]+a[l].y,dp[i][j][k]);
							if(k)dp[i][j][k]=max(dp[i][j][k-1]+a[l].z,dp[i][j][k]);
							ans=max(dp[i][j][k],ans);
						}
						
					}
				}
			}
			cout<<ans<<endl;
		}
		else
		{
			for(long long i=1;i<=n;i++)
			{
				cin>>b[i].x>>b[i].y>>b[i].z;
			}
			sort(b+1,b+1+n,cmp);
			ans=0;
			for(long long i=1;i<=n;i++)
			{
				if(i<=n/2)ans+=b[i].x;
				else ans+=b[i].y;
			}
			cout<<ans<<endl;
		}
	}
 } 
