#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
long long ksm(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	if(y==1)
	{
		return x;
	}
	long long z=ksm(x,y/2);
	z=(z*z)%mod;
	return (z*ksm(x,y%2))%mod;
}
long long n,m,p,jc[510],ny[510],a[510],s;
string st;
long long C(long long x,long long y)
{
	long long s=(jc[y]*ny[y-x])%mod;
	s=(s*ny[x])%mod;
	return s;
}
void workrunx()
{
	long long x,y=n+1;
	for(long long i=1;i<=n;i++)
	{
		if(st[i]=='1')
		{
			x=i-1;
			break;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		if(a[i]>x)
		{
			y=i;
			break;
		}
	}
	y=(n-y+1)*jc[n-1];
	y%=mod;
	cout<<y<<endl;
	return;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>st;
	st=" "+st;
	for(long long i=1;i<=n;i++)
	{
		if(st[i]=='1')
		{
			s++;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=0)
		{
			p++;
		}
	}
	sort(a+1,a+n+1);
	if(s<m || p<m)
	{
		cout<<0;
		return 0;
	}
	jc[0]=1;
	for(long long i=1;i<=n;i++)
	{
		jc[i]=jc[i-1]*i;
		jc[i]%=mod;
	}
	ny[n]=ksm(ny[n],mod-2);
	for(long long i=n-1;i>=0;i--)
	{
		ny[i]=ny[i+1]*i;
		ny[i]%=mod;
	}
	if(s==n)
	{
		cout<<jc[n];
		return 0;
	}
	if(m==1)
	{
		workrunx();
		return 0;
	}
	return 0;
}
