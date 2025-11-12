#include  <bits/stdc++.h>
using namespace std;
int x[200050],y[200050],z[200050];
int dp[205][205][205];
int a=0,b=0,c=0,sum;
long long ans=0;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int	t,n;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)cin>>x[j]>>y[j]>>z[j];
		for(int k=1;k<=n;k++)
		{
			if(dp[a][b][c]+x[k]>dp[a][b][c]+y[k]&&dp[a][b][c]+x[k]>dp[a][b][c]+z[k]){
				dp[a+1][b][c]=dp[a][b][c]+x[k];
				a++;
			}
			else{
				if(dp[a][b][c]+y[k]>dp[a][b][c]+z[k]){
					dp[a][b+1][c]=dp[a][b][c]+y[k];
					b++;
				}
				else {
					dp[a][b][c+1]=dp[a][b][c]+z[k];
					c++;
				}
			}
			ans=dp[a][b][c];
			//cout<<dp[a][b][c]<<" ";
		}
		cout<<ans;
		ans=0;
		for(int za=0;a<=n/2;a++)
			for(int zb=0;b<=n/2;b++)
				for(int zc=0;c<=n/2;c++)
					dp[za][zb][zc]=0;
	 } 

 	return 0;
}
