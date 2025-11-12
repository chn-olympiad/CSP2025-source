#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int pow_(int x,int y)
{
	int re=1;
	while(y){
		if(y&1) re=(re*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	} return re;
}
int n,m,c[505];
int jc[505],ny[505];
int ans=0,f[505];
string s;
void dfs(int x,int sum)
{
//	cout<<x<<' '<<sum<<'\n';
//	for(int i=1;i<=n;i++) cout<<f[i]<<' ';cout<<'\n';
	if(sum==m)
	{
		ans=ans+jc[n-x];
		return; 
	}
	if(x==n)
	{
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!f[i])
		{
			f[i]=x+1;
			if(c[i]>(x-sum)&&s[x+1]=='1') dfs(x+1,sum+1);
			else dfs(x+1,sum);
			f[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>c[i];
	jc[0]=1;
	for(int i=1;i<=n;i++) jc[i]=(jc[i-1]*i)%mod;
	ny[n]=pow_(jc[n],mod-2);
	for(int i=n-1;i>=1;i--)
	{
		ny[i]=(ny[i+1]*i)%mod;
	}
	if(n<=18)
	{
		dfs(0,0);
		cout<<ans; 
		return 0;
	}
	cout<<jc[n];
}
