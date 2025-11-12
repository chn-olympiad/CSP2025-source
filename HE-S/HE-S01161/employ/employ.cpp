#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,a[505];
string s;
int main()
{
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int cnt1=0,cnt0=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			cnt1++;
		}
		else if(s[i]=='0')
		{
			cnt0++;
		}
	}
	if(cnt1==n)
	{
		int ans=1;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
			ans%=mod;
		}
	}
	else if(cnt0==n)
	{
		cout<<0;
	}
	else
	{
		int ans=1;
		for(int i=1;i<=cnt1;i++)
		{
			ans*=i;
			ans%=mod;
		}
	}
	return 0;
}
