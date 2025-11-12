#include <iostream>
#include <queue>
using namespace std;

int arr[100005][5];
int dp[205][205][205];
int main()
{
	//70 pts
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>arr[i][j];
			}
		}
		if(n>200)
		{
			int ans=0;
			priority_queue<int,vector<int>,greater<int> > q;
			for(int i=1;i<=n;i++)
			{
				ans+=arr[i][1];
				q.push(arr[i][1]-arr[i][2]);
			}
			int cnt=n/2;
			while(cnt--)
			{
				ans-=q.top();
				q.pop();
			}
			cout<<ans<<'\n';
		}else
		{
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					dp[0][i][j]=-1e9;
				}
			}
			dp[0][0][0]=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=0;j<=n;j++)
				{
					for(int k=0;k<=n;k++)
					{
						dp[i][j][k]=dp[i-1][j][k]+arr[i][3];
						if(j)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+arr[i][1]);
						}
						if(k)
						{
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+arr[i][2]);
						}
					}
				}
			}
			int ans=0;
			for(int i=0;i<=n/2;i++)
			{
				for(int j=0;j<=n/2;j++)
				{
					if(n-i-j>n/2)
					{
						continue;
					}
					ans=max(ans,dp[n][i][j]);
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
