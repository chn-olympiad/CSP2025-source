#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>

using namespace std;

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	vector<int>a(n+1);
	vector<int>sum(n+1,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	unordered_map<int,int>mp;
	mp[0]=0;
	vector<int>dp(n+1,0);
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(mp.count(sum[i]^k))
		{
			dp[i]=max(dp[i],dp[mp[sum[i]^k]]+1);
		}
		mp[sum[i]]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
