#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k;
int a[500010];
int sum[500010];
int ans;
int x;
int dp[500010];
struct node{
	int st,ed;
}b[500010];
int len;
int main()
{
//	freopen("xor.in","r",stdin);
//	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum[i]=(k^a[i]);
	for(int i=1,cnt;i<=n;i++)
	{
		if(!sum[i])
		{
			b[++len].st=i;
			b[len].ed=i;
			dp[len]=1;
			continue;
		}
		cnt=sum[i];
		for(int j=i+1;j<=n;j++)
		{
			cnt=cnt^sum[j];
			if((j-i+1)%2==0&&cnt==k)
				b[++len].st=i,b[len].ed=j,dp[len]=1;
			if((j-i+1)%2==1&&cnt==0)
				b[++len].st=i,b[len].ed=j,dp[len]=1;
		}
	}
	for(int i=1;i<=len;i++)
	{
//		cout<<b[i].st<<' '<<b[i].ed<<'\n';
		for(int j=1;j<i;j++)
		{
			if(b[j].ed<b[i].st)
				dp[i]=max(dp[i],dp[j]+1);
		}
		ans=max(dp[i],ans);
	}
	cout<<ans;
	return 0;
}
