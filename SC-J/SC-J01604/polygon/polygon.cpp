#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10,mod=998244353;
int n,a[maxn],ans,book[maxn],t,f[maxn];
int pw(int x,int y)
{
	if(y==0)return 1;
	if(y==1)return x;
	int aaa=1;
	if(y%2)
	{
		aaa=x*pw(x,y-1);
		aaa%=mod;
	}
	else 
	{
		aaa=pw(x,y/2);
		aaa*=aaa;
		aaa%=mod;
	}
	return aaa;
}
void dfs(int x,int sum,int mx,int m)
{
	if(x==n)
	{
		if(sum>2*mx&&m>=3)
		{
			ans++;
			ans%=mod;
//			for(int i=1;i<=n;i++)cout<<book[i]<<' ';
//			cout<<sum<<' '<<mx;
//			cout<<endl;
		}
		return ;
	}
	book[x]=1;
	dfs(x+1,sum+a[x+1],a[x+1],m+1);
	book[x]=0;
	dfs(x+1,sum,mx,m);
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],t=max(t,a[i]);
	if(t==1)
	{
		f[0]=1;
		for(int i=1;i<=n;i++)f[i]=f[i-1]*i,f[i]%=mod;
		for(int i=3;i<=n;i++)
			ans+=(f[n]*pw(f[i],mod-2)%mod*pw(f[n-i],mod-2)%mod),ans%=mod;
		cout<<ans;
	}
	else
	{
		sort(a+1,a+n+1);
		dfs(1,0,0,0);
		book[1]=1;
		dfs(1,a[1],a[1],1);
		cout<<ans;
	}
	return 0;
//	cout<<pw(2,3)<<endl;
//	
}