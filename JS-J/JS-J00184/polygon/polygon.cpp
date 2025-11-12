#include <iostream>
#include <cstdio>
using namespace std;
long long fastm(int b)
{
	if(b==1)
	return 2;
	if(b%2==0)
	{
		int t=fastm(b/2);
		return t*t%998244353;
	}
	int t=fastm(b-1);
	return t*2%998244353;
}
int fj(int a,bool* e)
{
	int l;
	for(l=0;a>0;l++)
	{
		e[l]=a%2;
		a/=2;
	}
	return l ;
}
int s[25];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,themost=0;
	cin>>n;
	if(n>25)
	{
		cout<<fastm(n)-1-n-n*(n-1)/2;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin>>s[i];
	}
	long long d=7,e=fastm(n);
	bool g[n];
	for(d=7;d<=e;d++)
	{
		int zx=fj(d,g),sun=0,max=0,ty=0;
		for(int i=0;i<zx;i++)
		{
			if(g[i])
			{
				ty++;
				sun+=s[i];
				if(s[i]>max)
				max=s[i];
			}
		}
		if(ty>2 && (sun>max*2))
		themost++;
	}
	cout<<themost;
	return 0;
}
