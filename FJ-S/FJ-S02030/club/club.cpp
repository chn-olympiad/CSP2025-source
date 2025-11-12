#include<iostream>
using namespace std;
int dp[50001][101][101],a[201][4];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,i,j,k,len,ans=0;
	cin>>t;
	while(t--)
	{
		ans=0;
		cin>>n;
		for(i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		dp[0][0][0]=0;
		for(len=1;len<=n;len++)
		{
			for(i=0;i<=n/2;i++)
			{
				for(j=0;j<=n/2;j++)
				{
					k=len-i-j;
					if(k>n/2)
					continue;
					int x=0,y=0,z=0;
					if(i>=1)
					x=dp[i-1][j][k]+a[len][1];
					if(j>=1)
					y=dp[i][j-1][k]+a[len][2];
					if(k>=1)
					z=dp[i][j][k-1]+a[len][3];
					dp[i][j][k]=max(x,max(y,z));
					if(len==n)
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
