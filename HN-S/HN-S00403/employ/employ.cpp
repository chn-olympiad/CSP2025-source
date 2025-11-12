#include<bits/stdc++.h>
using namespace std;
int n,m,c[507],mod=998244353,A=1,cnt=0,o=1e9,maxi=0,v[507],a[507],ans=0;
string s;
void dfs(int x)
{
	if(x>n)
	{
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='0' || cnt>=c[a[i]])
			{
				cnt++;
			}
		}
		if(n-cnt>=m)
		{
			ans++;
			ans=ans%mod;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			a[x]=i;
			dfs(x+1);
			a[x]=0;
			v[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s="#"+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		maxi=max(maxi,c[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='0')
		{
			A=0;
		}
		else
		{
			cnt++;
			o=min(i,o);
		}
	}
	if(A==1)
	{
		ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans%mod;
		return 0;
	}
	if(n==m)
	{
		cout<<0;
		return 0;
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	if(maxi<o)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		ans=1;
		long long cnt=0;
		for(int i=1;i<=n-1;i++)
		{
			ans=(ans*i)%mod;
		}
		for(int i=1;i<=n;i++)
		{
			if(c[i]>=o)
			{
				cnt++;
			}
		}
		ans=(ans*cnt)%mod;
		cout<<ans%mod;
		return 0;
	}
	dfs(1);
	cout<<ans%mod;
	return 0;
}
