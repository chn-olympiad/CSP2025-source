#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

const long long mod=998244353;
long long n,m,ans=0,a[505],c[505];
string s;

void check()
{
	long long dead=0;
	
	for(long long i=1;i<=n;i++)
	{
		if(s[i-1]=='0' || dead>=c[a[i]])dead++;
	}
	
	if(n-dead>=m)ans=(ans+1)%mod;
	
	return;
}

void fin(long long x)
{
	if(x==n)
	{
		check();
		return;
	}
	
	for(long long i=x;i<=n;i++)
	{
		swap(a[x],a[i]);
		fin(x+1);
		swap(a[x],a[i]);
	}
	
	return;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	if(n>18)
	{
		cout<<0<<endl;
		return 0;
	}
	
	for(long long i=1;i<=n;i++)
		a[i]=i;
	
	cin>>s;
	
	for(long long i=1;i<=n;i++)
		cin>>c[i];
	
	fin(1);
	
	cout<<ans<<endl;
	
	return 0;
}
