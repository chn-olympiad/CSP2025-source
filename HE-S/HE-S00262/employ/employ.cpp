#include<bits\stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,vis[20],a[20],re[20],ans;
string s;
void dfs(int x)
{
	if(x==n)
	{
		int meilu=0,jishu=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='0'||meilu>=re[a[i]])
			{
				meilu++;
				continue;
			}
			jishu++;
		}
		if(jishu>=m)
			ans=(ans+1)%mod;
		return ;
	}
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
		cin>>re[i];
	if(n<=18)
	{
		dfs(0);
		cout<<ans;
	}
	else
	{
		ans=1;
		int oi=n;
		for(int i=0;i<n;i++)
			if(re[i]==0)
				n--;
		if(n<m)
		{
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
	return 0;
}
