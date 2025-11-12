#include<bits/stdc++.h>
using namespace std;
long long k(int x,int y)
{
	long long p=1;
	for(int i=x;i>=x-y;i--)
	{
		p*=x;
		if(p>=998244353)
		{
			p-=998244353;
		}
	}
	for(int i=y;i>=1;i--)
	{
		p/=i;
	}
	return p;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m,a[5005],f=0;
	long long cnt=0;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		if(a[i]!=1)
		{
			f=1;
		}
	}
	if(f)
	{
		for(int i=3;i<=m;i++)
		{
			cnt+=k(m,i);
			if(cnt>=998244353)
			{
				cnt-=998244353;
			}
		}
		cout<<cnt;
		return 0;
	}
	else
	{
		if(a[1]+a[2]>a[3]||a[2]+a[3]>a[1]||a[1]+a[3]>a[2])
		{
			cout<<1;
		}
		else
		{
			cout<<0;
		}
	}
	return 0;	
}
