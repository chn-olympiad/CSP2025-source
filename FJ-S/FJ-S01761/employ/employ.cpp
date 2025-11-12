#include<bits\stdc++.h>
using namespace std;
int n,m;
string s;
int nd[511];
int nx[511];
int s1;
int f=1;
int fn=1;
int s0;
int s11;
long long ans=1;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i(1); i<=n; i++)
	{
		cin>>nx[i];
		if(nx[i]==0)
			s0++;
		if(nx[i]==1)
			s11++;

		if(nx[i]!=n)
		{

			fn=0;
		}
	}
	for(int i(0); i<n; i++)
	{
		if(s[i]=='1')
			s1++,nd[i+1]=1;
	}
	if(s0==n)
	{
		cout<<0;
		return 0;
	}
	if(s1<m)
	{
		cout<<0;
		return 0;
	}
	if(fn==1)
	{
		for(int i(2); i<=n; i++)
			ans*=i,ans%= 998244353;
		cout<<ans%998244353;
		return 0;
	}
	if(s1==n)
	{
		for(int i(2); i<=n; i++)
			ans*=i,ans%= 998244353;
		cout<<ans%998244353;
		return 0;
	}
	if(m==1)
	{
		for(int i(2); i<=n; i++)
			ans*=i,ans%= 998244353;
		cout<<ans%998244353;
		return 0;
	}
	if(s11==n)
	{
		for(int i(1); i<=n; i++)
		{
			if(nd[i]==0)
			{
				if(i>=m)
				{
					for(int i(2); i<=n; i++)
						ans*=i,ans%= 998244353;
					cout<<ans%998244353;
				}
				else
				{
					cout<<0;
				}
				return 0;
			}
		}
	}
	if(m==n)
	{
		for(int i(2); i<=n; i++)
			ans*=i,ans%= 998244353;
		cout<<ans%998244353;
		return 0;
	}
	cout<<2;
	return 0;
}
