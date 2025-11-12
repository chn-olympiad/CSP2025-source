#include<bits/stdc++.h>
using namespace std;

int a[500005],dp[500005][2];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		dp[i][1]=dp[i-1][1];
		dp[i][0]=dp[i-1][0];
		if(a[i]==m)
		{
			dp[i][0]++;
			dp[i][1]=i;
		}
		else
		{
			int x=a[i];
			for(int j=i-1;j>dp[i][1];j--)
			{
				int y=a[j];
				x=(x|y);
				if(x==m)
				{
					dp[i][1]=i;
					dp[i][0]++;
					break;
				}
			}
		}
	}
	cout<<dp[n][0];
	return 0;
}