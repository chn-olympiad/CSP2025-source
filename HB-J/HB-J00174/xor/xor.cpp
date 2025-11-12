#include<bits/stdc++.h>
using namespace std;
int a[1010];
int dp[1005][1005],ansdp[1005],b[1005][1005];
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k,ans=0,cnt2=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(j==i) dp[i][j]=a[i];
			else
			{
				dp[i][j]=dp[i][j-1]^a[j];
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==k) 
			{
				b[cnt2+1][1]=i;
				b[cnt2+1][2]=j;
				cnt2++;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(dp[i][j]==k) 
			{
				ansdp[j]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(b[i][1]<b[j][1])
			{
				swap(b[i][1],b[i][1]);
				swap(b[i][2],b[i][2]);
			}
		}
	}
	for(int i=1;i<cnt2;i++)
	{
		for(int j=1;j<cnt2;j++)
		{
			if(b[i][1]!=b[j][1]) break;
			if(b[i][2]<b[j][2]) swap(b[i][2],b[j][2]);
		}
	}
	int cnt=1;
	while(cnt<n)
	{
		cnt+=b[cnt][2];
		ans++;
	}
	cout<<ans;
	return 0;
}
