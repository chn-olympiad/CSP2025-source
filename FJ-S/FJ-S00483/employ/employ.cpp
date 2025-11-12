#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[510],c[510],b[510],vis[510],ans,mod=998244353;
void dfs(int now)
{
	if(now==n+1)
	{
		int tmp=0,tmp2=0;
		for(int i=1;i<=n;i++)
		{
			if(c[b[i]]<=tmp)
			{
				tmp++;
			}
			else if(a[i]==0)
			{
				tmp++;
			}
			else if(a[i]==1)
			{
				tmp2++;
			}
		}
		if(tmp2>=m)
		{
			ans=(ans+1)%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			b[now]=i;
			dfs(now+1);
			vis[i]=0;
			b[now]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>s;
		if(s=='0')
		{
			a[i]=0;
		}
		else
		{
			a[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
