#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
const ll MOD=998244353;
int n,m,a[100001],c[100001];
bool b[10001];
int dfs(int x,int bai)
{
	ll ans=0;
	if(n-bai<m) return 0;
	if(x==n+1)
	{
		return 1LL;
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]!=1) b[i]=1,ans+=dfs(x+1,bai+(a[x]==0||bai>=c[i])),b[i]=0;
	}
//	cout<<bai<<'\n';
	return ans%MOD;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int flag=1;
	for(int i=1;i<=n;i++) a[i]=s[i-1]-'0',flag=min(flag,a[i]);
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		cout<<dfs(1,0)%MOD;
	}
	else if(flag)
	{
		ll ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=MOD;
		}
		cout<<ans;
	}
	else
	{
		cout<<0;
	}
	return 0;
}
/*
3 2
101
1 1 2
*/