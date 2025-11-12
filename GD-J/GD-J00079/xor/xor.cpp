#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],dp[500005],s[500005],l=1;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		for(int j=l;j<=i;j++)
		{
			int x=s[i]^s[j-1];
			if(x==k)  
			{
				dp[i]=max(dp[i],dp[j-1]+1);
			}
		}
		if(dp[i]!=dp[i-1])  l=i+1;
	}
	cout<<dp[n];
	return 0;
}
