#include<bits/stdc++.h>
using namespace std;
int n,a[500001],k,sumxor[500001],l[500001],dp[500001][1];
map<int,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	sumxor[0]=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sumxor[i]=sumxor[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==k)
		{
			l[i]=i;
		}
		else if(mp[k^sumxor[i]])
		{
			l[i]=mp[k^sumxor[i]]+1;
		}
		else if(k==sumxor[i])
		{
			l[i]=1;
		}
		else
		{
			l[i]=-1;
		}
		mp[sumxor[i]]=i;
	}
	dp[0][0]=dp[1][0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
		if(l[i]==-1)
		{
			continue;
		}
		dp[i][1]=max(dp[l[i]-1][0],dp[l[i]-1][1])+1;
	}
	cout<<max(dp[n][0],dp[n][1]);
	return 0;
}
