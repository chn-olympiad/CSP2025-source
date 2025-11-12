#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[114514];
signed main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mx=-999999999,pd=1,x=0,y=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		if(a[i]!=1) pd=0;
		x+=(a[i]==0);
		y+=(a[i]==1);
	}
	if(pd)
	{
		if(k==0)
		{
			cout<<n/2;
			return 0;
		}
		else if(k==1)
		{
			cout<<n;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	if(mx==1)
	{
		if(k==0)
		{
			cout<<x+(y/2);
			return 0;
		}
		else if(k==1)
		{
			cout<<y;
			return 0;
		}
		else
		{
			cout<<0;
			return 0;
		}
	}
	int now=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		now^=a[i];
		if(a[i]==k)
		{
			i++;
			ans++;
			now=a[i];
			continue;
		}
		if(now==k)
		{
			i++;
			ans++;
			now=a[i];
			continue;
		}
	}
	cout<<ans;
}
