#include<bits/stdc++.h>
using namespace std;
int a[505];
int x[505];
long long ans=1;
int n,m;
string s;
void dfs(int p)
{
	if (p==n+1)
	{
		int qs=0,cg=0;
		for (int i=1;i<=n;i++)
		{
			if (s[i]=='0')
			{
				qs=qs+1;
			}
			else
			{
				if (qs>=a[x[i]])
				{
					qs=qs+1;
				}
				else
				{
					cg=cg+1;
				}
			}
		}
		if (cg>=m)
		{
			ans=ans+1;
		}
		return;
	}
	for (int i=1;i<=n;i++)
	{
		if (x[i]==0)
		{
			x[i]=p;
			dfs(p+1);
			x[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++)
	{
		if (s[i]=='0')
		{
			ans=0;
		}
	}
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]==0)
		{
			ans=0;
		} 
	}
	if (m==n)
	{
		for (long long i=1;i<=n;i++)
		{
			ans=ans*i;
			ans=ans%998244353;
		}
		cout<<ans<<endl;
	}
	else
	{
		ans=0;
		s=' '+s;
		dfs(1);
		cout<<ans<<endl;
	}
}
