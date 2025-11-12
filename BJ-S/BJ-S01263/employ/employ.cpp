#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505,mod=998244353;
int a[N];
bool v[N];
int n,m;
ll res;
string s;
void dfs(int x,int cnt,int sum)
{
	if(x==n+1)
	{
		if(sum>=m)
			res++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i])
			continue;
		if(s[x-1]=='0'||cnt>=a[i])
		{
			v[i]=1;
			dfs(x+1,cnt+1,sum);
			v[i]=0;
		}
		else
		{
			v[i]=1;
			dfs(x+1,cnt,sum+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	bool f=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(s[i-1]!='1')
			f=1;
	}
	if(!f)
	{
		ll ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	dfs(1,0,0);
	cout<<res;
	return 0;
}
