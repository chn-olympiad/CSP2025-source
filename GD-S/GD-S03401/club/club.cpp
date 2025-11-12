#include<iostream>
const int N = 1e5+10;
using namespace std;
int t,n,a[N][4],dp[N][4],b[N];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=3;j++)
				cin>>a[i][j];
		for(int i = 1;i<=n;i++)
		{
			b[i-1]=0;
			for(int j = 1;j<=n/2;j++)
			{
				if(dp[i][j-1]>=dp[i-1][j-1]+a[i][1])
				dp[i][j]=dp[i][j-1];
				else if(dp[i][j-1]<dp[i-1][j-1]+a[i][1]&&b[i]==0){
					dp[i][j]=dp[i-1][j-1]+a[i][1];
					b[i]=1;
				}
				cout<<dp[i][j]<<endl;
			}
		}
	}
	cout<<dp[n][n/2];
	return 0;
 } 
