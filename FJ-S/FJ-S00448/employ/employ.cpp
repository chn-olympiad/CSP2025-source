#include <bits/stdc++.h>
using namespace std;

/*
Mind:
1.Group Backpack
*/

int dp[114514][4],num[114514][4][4],n,a[114514][4];

void mai()
{
	memset(dp,0,sizeof(dp));
	memset(num,0,sizeof(num));
	memset(a,0,sizeof(a));
	cin >> n;
	for (int i=1;i<=n;i++)//input
	{
		for (int j=1;j<=3;j++)cin >> a[i][j];
	}
	for (int i=1;i<=3;i++)//init dp
	{
		dp[1][i]=a[1][i];
		num[1][i][i]=1;
	}
	//cout << endl;
	for (int i=2;i<=n;i++)//dp
	{
		for (int j=1;j<=3;j++)
		{
			//[i][j]---[i-1][k]
			for (int k=1;k<=3;k++)
			{
				if (num[i-1][j][k]+1<=i/2||i%2==0)
				{
					if (dp[i][j]<dp[i-1][k]+a[i][j])
					{
						dp[i][j]=dp[i-1][k]+a[i][j];
						num[i][j][1]=num[i-1][k][1];
						num[i][j][2]=num[i-1][k][2];
						num[i][j][3]=num[i-1][k][3];
						//num[i][j][k]++;
						num[i][j][j]++;
					}
				}
			}
		}
	}
	/*for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=3;j++)cout << dp[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=3;j++)
		{
			for (int k=1;k<=3;k++)cout << num[i][j][k];
			cout << ' ';
		}
		cout << endl;
	}*/
	int res=0;
	for (int i=1;i<=3;i++)
	{
		if (dp[n][i]>res)res=dp[n][i];
	}
	cout << res << endl;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int ttt;
	cin >> ttt;
	for (int i=1;i<=ttt;i++)
	{
		mai();
	}
	return 0;
}
