#include<bits/stdc++.h>
using namespace std;
const int N=5e3+1;
const int mod=998244353 ;

int n;
int a[N];
long long ans=0;
long long m=1;
long long nn=1;
long long m_n=1;

bool cmp(int x,int y)
{
	return x>y;
}

void f(int x)
{
	nn=1;
	m_n=1; 
	for(int i=1;i<=x;i++)nn=(nn*i)%mod;
	for(int i=1;i<=(n-x);i++)m_n=(m_n*i)%mod;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		m=(m*i)%mod;
	}
	
	int bj=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=1)bj=1;
	}
	
	sort(a+1,a+1+n);
	
	if(!bj)
	{
		for(int i=3;i<=n;i++)
		{
			f(i);
			ans=(ans+m/(nn*m_n)%mod)%mod;
		}
		cout<<ans;
		return 0;
	}
	else
	{
		if(n==3)
		{
			if(a[3]>=a[1]+a[2])cout<<0;
			else cout<<1;
			return 0;
		}
		else 
		{
			cout<<0;
		}
	}
	
	
	return 0;
 } 