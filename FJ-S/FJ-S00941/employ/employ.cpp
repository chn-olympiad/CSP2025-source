#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+5;
const int mod=998244353; 
int c[maxn];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			cnt++;
		}
	}
	if(cnt<m)
	{
		cout<<0;
		return 0;
	}
	int p=n;
	for(int i=1;i<=n;i++)
	{
		if(c[i]==0)
		{
			p--;
		}
	}
	if(p<m)
	{
		cout<<0;
		return 0;
	}
	if(n==m)
	{
		if(p<n)
		{
			cout<<0;
			return 0;
		}
		else
		{
			if(cnt==n)
			{
				cout<<1;
				return 0;
			}
			else
			{
				cout<<0;
				return 0;
			}
		}
	}
	if(cnt==n)
	{
		long long ans=1;
		for(int i=1;i<=n;i++)
		{
			ans=(ans*i)%mod;
		}
		cout<<ans;
		return 0; 
	}
	return 0;
 }

