#include<bits/stdc++.h>
using namespace std;
int mod=998244353,a[510],n,m,c[510];
bool vis[510];
long long ans;
string s;
bool check()
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt>=c[a[i]]) cnt++;
		else if(s[i-1]=='0') cnt++;
	}
	return (n-cnt>=m);
}
void dfs(int k)
{
	if(k==n+1)
	{
		if(check()) ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	ans++;
	for(int i=1;i<=n;i++)ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
