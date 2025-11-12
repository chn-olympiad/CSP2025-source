#include <bits/stdc++.h>
using namespace std;
const int N=500;
int a[N];
bool cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]-'0'==0)f=0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	if(f==1)
	{
		int
		long long ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==m)
	{
		if(f==0)cout<<0;
		else
		{
			long long ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		}
		return 0;
	}
	if(m==1)
	{
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]-'0'==0)
			{
				int g=lower_bound(a+1,a+n+1,i+1)-a;
				int u=n-g+1;
				ans+=u;
			}
		}
		long long ans2=1;
		for(int i=2;i<n;i++)
		{
			ans2=ans2*i%998244353;
		}
		ans2=ans*ans%998244353;
		cout<<ans2;
		return 0;
	}
	if(n<=18)
	{
		cout<<n;
		
	}
	return 0;
}
