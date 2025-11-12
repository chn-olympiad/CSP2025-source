#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5; 
int n,k,a[N],sum[N];
int dp[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(sum[i]==k)dp[i]=1;
		dp[i]=max(dp[i],dp[i-1]);
		for(int j=i-1;j>=1;j--)
		{
			if((sum[j]^sum[i])==k)dp[i]=max(dp[i],dp[j]+1);
		}
	}
	cout<<dp[n];
	return 0;
}
