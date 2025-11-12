#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
int dp[15][15];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int t=n*m;
	cin>>a[1];
	int num=a[1];
	for(int i=2;i<=t;i++)cin>>a[i];
	sort(a+1,a+1+t,cmp);
	int k=1;
	for(int i=1;i<=n;i++)
	{
		if(i%2!=0)
		{
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=a[k];
				k++;
			}
		}else
		{
			for(int j=m;j>=1;j--)
			{
				dp[i][j]=a[k];
				k++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(dp[i][j]==num)
			{
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
