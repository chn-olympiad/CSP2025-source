#include<bits/stdc++.h>
using namespace std;
//#define int long long <------------------------
int n,k;
int a[500001];
int sum[500001];
int dp[500001];
unordered_map<int,int> lst;
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(sum[i]==k) dp[i]=max(1,dp[i]);
		int q=lst[sum[i]^k];
		if(q!=0) dp[i]=max(dp[i],dp[q]+1);
		lst[sum[i]]=i;
	}
	cout<<dp[n];
	return 0;
}
/*

shen shou bao you

*/
