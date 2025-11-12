#include<bits/stdc++.h>
using namespace std;
int n,k,cnt=0,num=0;
int a[1005],c[1005];
int l[1005],r[1005],d[1005];
int dp[1005][1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1) num++;
		c[i]=a[i]^c[i-1];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
		{
			if((c[j]^c[i-1])==k)
			{
				cnt++;
				l[cnt]=i;
				r[cnt]=j;
			}
		}
	for(int i=1;i<=cnt;i++) if(d[l[i]]==0) d[l[i]]=i;
	for(int i=n;i>=1;i--)
	{
		dp[i][0]=max(dp[i+1][0],dp[i+1][d[i+1]]);
		for(int j=1;j<=cnt;j++)
		{
			if(i==l[j]) dp[i][j]=max(dp[i][j],dp[r[j]][j]+1);
			if(i==r[j]) dp[i][j]=dp[i+1][d[i+1]];
			if(i==l[j]==r[j]) dp[i][j]=max(dp[i+1][0],dp[i+1][d[i+1]])+1;
		}
	}
	cout<<max(dp[1][1],dp[1][0]);
	return 0;
}