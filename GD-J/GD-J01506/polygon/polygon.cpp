#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a<b;
}
int sz[5010];
int dp[5010][10010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxi=-1;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>sz[i];
		maxi=max(maxi,sz[i]);
	}
	sort(sz+1,sz+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=2*maxi;j++)
		{
			if(i==1)
			{
				dp[i][j]=(j<=sz[i]);
				continue;
			}
			dp[i][j]=dp[i-1][max(0,j-sz[i])]+dp[i-1][j];
		}
	}
	for(int i=3;i<=n;i++)
	{
		ans+=dp[i][2*sz[i]];
	}
	cout<<ans;
	return 0;
} 
