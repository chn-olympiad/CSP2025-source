#include<bits/stdc++.h>
using namespace std;
int t,n,a[100010][4],dp[100010][4],num[4],c[100010],sum=0;
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			c[i]=a[i][1];
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n/2;i++)
		{
			sum+=c[i];
		}
		cout<<sum<<endl;
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				dp[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				if(num[j]<n/2)
				{
					num[j]++;
					dp[i][j]=max(dp[i][j-1],max(dp[i-1][j],dp[i][j-1]-a[i][j-1]+a[i][j]));
				}
				else
				{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cout<<dp[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<dp[n][3]<<endl;
		num[1]=0;
		num[2]=0;
		num[3]=0;*/
	}
	return 0;
}
