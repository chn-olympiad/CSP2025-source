#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],c[2000010],dp[500010];
int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	memset(c,-1,sizeof(c));
	c[0]=0;
	for(long long i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		long long t=(b[i]^m);
		if(c[t]!=-1)
		{
			dp[i]=max(dp[i],dp[c[t]]+1ll);
		}
		c[b[i]]=i;
	}
	cout<<dp[n];
	return 0;
}

