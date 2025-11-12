#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define ref(i,a,b) for(int i=a;i>=b;--i)
#define rek(i,a,b) for(int i=a;i<b;++i)
using namespace std;
const int mod=998244353;
int T,n,m,ans;
int a[5005];
int s[5005];
int f[5005][5005];
vector<int> v;
int qpow(int x,int y)
{
	int res=1;
	while(y)
	{
		if(y&1) res=res*x%mod;
		x=x*x%mod,y>>=1;
	}
	return res;
}
void init(int n,int m)
{
	f[1][1]=1;
	rep(i,2,n) rep(j,1,i) f[i][j]=(f[i-1][j-1]+f[i-1][j])%mod;
}
int query(int x,int y)
{
	return f[x+1][y+1];
}
void dfs(int x,int s,int fa)
{
	if(x>n)
	{
		if(s>a[fa]*2) ans++;
		return;
	}
	dfs(x+1,s,fa),dfs(x+1,s+a[x],x);
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	rep(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	rep(i,1,n) s[i]=s[i-1]+a[i];
	init(n+1,n+1);
	if(a[n]==1)
	{
		rep(i,3,n) ans=(ans+query(n,i))%mod;
		return cout<<ans,0;
	}
	return dfs(1,0,0),cout<<ans,0;
}
