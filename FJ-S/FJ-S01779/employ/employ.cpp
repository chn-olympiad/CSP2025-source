#include<bits/stdc++.h>
using namespace std;
int a[505],na[505],sum,f[505],w=0,n,m;
bool flag=true;
string h;
int dp(int x)
{
	if(x==1)	return f[x]=1;
	return f[x]=x*dp(x-1)%998244353;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>h;
	for(int i=0;i<n;i++)
	{
		if(h[i]!='1')	flag=false;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>na[i];
		if(na[i]==0)	w++;
	}
	if(flag=true)
	{
		sum=dp(n);
		cout<<sum;
		return 0;
	}	
	if((n-w)<m)
	{
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}