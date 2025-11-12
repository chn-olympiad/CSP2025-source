#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k,op,op1,a[N],xo[N],dp[N];
int ans;
unordered_map<int,int> mp;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i],xo[i]=xo[i-1]^a[i],mp[xo[i]]=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]!=1){op=1;break;}
	}
	for(int i=1;i<=n;++i) if(a[i]!=0&&a[i]!=1){op1=1;break;}
	if(!op)
	{
		if(k) cout<<n;
		else cout<<n/2;
	}else if(!op1)
	{
		for(int i=1;i<=n;++i)
		{
			if(a[i]==k){++ans;}
			else{if(a[i+1]==a[i])++ans,++i;}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;++i)
		{
			if(mp[(xo[i]^k)]) dp[i]=max(dp[i],dp[mp[(xo[i]^k)]]+1);
			if(mp[xo[i]]) dp[i]=max(dp[i],dp[mp[xo[i]]]);
			mp[xo[i]]=i;
			dp[i]=max(dp[i-1],dp[i]);
		}
	//	for(int i=1;i<=n;++i) cout<<dp[i]<<" ";
		int c=0;
		for(int i=1;i<=n;++i) if(a[i]==k) ++c;
		for(int i=1;i<=n;++i) ans=max(ans,dp[i]);
		cout<<ans+c;
	}
	return 0;
}
/*lower:>= upper_bound:>*/
