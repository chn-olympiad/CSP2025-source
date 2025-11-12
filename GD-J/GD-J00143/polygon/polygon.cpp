#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n;
int a[5005];
bool vis[5005];
int cnt;
void dfs(int s,int now,int maxx)
{
	if(s>=n+1&&now>2*maxx&&now>0)
	{
		cnt++;
		cnt%=mod;
		return ;
	}
	if(s>=n+1) return ;
	vis[s]=1;
	dfs(s+1,now+a[s],max(maxx,a[s]));
	vis[s]=0;
	dfs(s+1,now,maxx);
}
int qpow(int x,int y)
{
	if(y==0) return 1;
	if(y==1) return x%mod;
	if(y==2) return x%mod*x%mod; 
	if(y%2==0) return qpow(x,y/2)*qpow(x,y/2)%mod;
	else return qpow(x,y/2)*qpow(x,y/2)%mod*x%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		mx=max(mx,a[i]);
	}
	if(mx<=1)
	{
		int ans=qpow(2,n)%mod;
		ans--;
		ans=(ans+mod-n)%mod;
		ans=(ans+mod-n*(n-1)/2)%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<cnt;
	return 0;
}
