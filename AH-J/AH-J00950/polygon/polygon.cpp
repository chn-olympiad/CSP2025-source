#include<bits/stdc++.h>
//luogu:1503820
//topscoding:509
using namespace std;
const long long mod=998244353;
long long n,s=0;
int a[5005],b[5005];
void fs(int i,long long ss,int maxn)
{
	ss+=a[i];
	maxn=max(maxn,a[i]);
	if(ss>maxn*2ll)
	{
		++s;
		s%=mod;
	}
	for(int j=i+1;j<=n;++j)
	{
		if(b[j]==0)
		{
			b[j]=1;
			fs(j,ss,maxn);
			b[j]=0;
		}
	}
	return;
}
long long C(int a,int b)
{
	unsigned long long s1=1,s2=1;
	for(int i=1;i<=a;++i)
	{
		s1*=b;
		s2*=a;
		s1%=mod;
		s2%=mod;
		--b;
		--a;
	}
	if(s2==0)
	{
		return 0;
	}
	return (s1/s2)%mod;
}
int td1()
{
	int maxn=INT_MIN;
	for(int i=1;i<=n;++i)
	{
		maxn=max(maxn,a[i]);
		s+=a[i];
	}
	if(s>maxn*2)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
long long td2()
{
	unsigned long long s=0;
	for(int i=3;i<=n;++i)
	{
		s+=C(i,n);
		s%=mod;
	}
	return s;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cin.tie(nullptr);
	bool f=true;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		if(a[i]>1)
		{
			f=false;
		}
	}
	if(n<3)
	{
		cout<<0;
	}
	else if(n==3)
	{
		cout<<td1();
	}
	else if(f)
	{
		cout<<td2();
	}
	else
	{
		fs(0,0,-1);
		cout<<s;
	}
	return 0;
}
/*
 CCCC   CCCC  FFFFF
C      C      F
C      C      FFFF
 CCCC   CCCC  F



			A        CCCCC
		   A A      C    
		  A   A     C
		 AAAAAAA    C    
		A       A    CCCCC
*/
