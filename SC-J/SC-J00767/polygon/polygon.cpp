#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int qpow(int x,int y)
{
	if(x==0)	return 0;
	int s=1,ss=x;
	while(y)
	{
		if(y&1)		s=s*ss%mod;
		ss=ss*ss%mod;
		y>>=1;
	}
	return s;
}
int n,a[5005],ans,dp[5005][5005];
bool vis[5005][5005];
bool cmd(int x,int y){return x>y;}
int f(int x,int y)
{
	if(y<0)	return 0;
	if(x>n)	return 1;
	if(vis[x][y])	return dp[x][y];
	vis[x][y]=1;
	return dp[x][y]=(f(x+1,y)+f(x+1,y-a[x]))%mod;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+n+1,cmd);
	for(int i=1;i<=n;i++){
		ans=(ans+(qpow(2,n-i)-f(i+1,a[i])+mod)%mod)%mod;
//		cout<<qpow(2,n-i)<<" "<<f(i+1,a[i])<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}