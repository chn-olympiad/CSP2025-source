#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,ans;
int maxn;
int a[5005];
int dp[N+5]; //x
int inv[5005];
void dfs(int k,int maxx,int total)
{
	if(k==n+1)
	{
		if(total>maxx*2)
			ans++;
		ans%=mod;
		return ;
	}
	dfs(k+1,max(maxx,a[k]),total+a[k]);
	dfs(k+1,maxx,total);
	return ;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	inv[1]=1;
	for(int i=2;i<=1145;i++)
		inv[i]=((mod-mod/i)*inv[mod%i])%mod;
	for(int i=1;i<=n;i++)
		cin>>a[i],maxn=max(maxn,a[i]);
	if(maxn==1)
	{
		if(n==3)
		{
			cout<<0<<"\n";
			return 0;
		}
		ans=1;
		ans*=n;
		ans%=mod;
		ans*=(n-1);
		ans%=mod;
		ans*=(n-2);
		ans%=mod;
		ans*=(n-3);
		ans%=mod;
		ans*=inv[24];
//		cout<<inv[6]<<" "<<"\n";
		ans%=mod;
		for(int i=1;i<=n-4;i++)
		{
			ans*=2;
			ans%=mod;
		}
		cout<<ans<<"\n";
		return 0;
	}
	dfs(1,0,0);
	cout<<ans<<"\n";
	return 0;
}
