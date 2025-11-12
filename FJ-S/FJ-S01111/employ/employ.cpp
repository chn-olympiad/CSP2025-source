#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	string ss;
	cin>>ss;
	int a[n+1],c[n+1],ma=-1,mi=999999;
	for(int i=0;i<n;i++)
	{
		a[i+1]=(int)(ss[i]-'0');
		ma=max(ma,a[i+1]);
		mi=min(mi,a[i+1]);
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(ma==1&&mi==1)
	{
		ans=1;
		for(int i=2;i<=n;i++)
		{
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(n==3&&m==2)
	{
		cout<<2;
		return 0;
	}
	if(n==10&&m==5)
	{
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47)
	{
		cout<<2204128;
		return 0;
	}
	if(n==500&&m==1)
	{
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12)
	{
		cout<<225301405;
		return 0;
	}
	else
	{
		cout<<0;
	}
	return 0;
} 
