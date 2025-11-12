#include<bits/stdc++.h>
using namespace std;

int n,m,a[500010],dp[500010],f[2000010],s[500010];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
	memset(f,0xc0,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1];
		if(f[s[i]^m]>=0) dp[i]=max(dp[i],dp[f[s[i]^m]]+1);
		f[s[i]]=i;
	}
	cout<<dp[n]<<endl;
	return 0;
}
