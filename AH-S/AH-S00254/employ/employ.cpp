#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int c[505],f[505],n,m,ans;
string s;
void dfs(int step,int cnt,int lose)
{
	if(cnt>m)
	{
		return ;
	}
	if(lose>n-m)
	{
		return ;
	}
	if(step==n+1)
	{
		if(cnt==m)
		{
			ans=(ans+1)%mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]==0)
		{
			f[i]=1;
			if(c[i]>lose&&s[step-1]=='1')
			{
				dfs(step+1,cnt+1,lose);
			}
			else
			{
				dfs(step+1,cnt,lose+1);
			}
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
