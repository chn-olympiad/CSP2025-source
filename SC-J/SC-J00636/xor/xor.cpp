#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],b[100],x,k,m,ans,mx;
long long ten(long long a)
{
	long long x=1;
	for(long long i=1;i<a;i++)
	{
		x*=10;
	}
	return x;
}
long long check(long long a)
{
	long long x=0;
	while(a>0)
	{
		x++;
		a/=10;
	}
	return x;
}
long long yh(long long a,long long b)
{
	long long c,d,n;
	if(b>a)
	{
		c=b;
		n=c;
		d=check(a);
		for(long long i=1;i<=d;i++)
		{
			if(a%10==n%10&&n%10==1)
			{
				c-=ten(i);
				a/=10;
				n/=10;
			}
			if(a%10!=n%10&&n%10==0)
			{
				c+=ten(i);
				a/=10;
				n/=10;
			}
		}
	}
	else
	{
		c=a;
		n=c;
		d=check(b);
		for(long long i=1;i<=d;i++)
		{
			if(b%10==n%10&&n%10==1)
			{
				c-=ten(i);
				b/=10;
				n/=10;
			}
			if(b%10!=n%10&&n%10==0)
			{
				c+=ten(i);
				b/=10;
				n/=10;
			}
		}
	}
	return c;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	while(k>0)
	{
		x++;
		b[x]=k%2;
		k/=2;
	}
	k=0;
	for(long long j=x;j>=1;j--)
	{
		k=k*10+b[j];
	}
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		x=0;
		while(a[i]>0)
		{
			x++;
			b[x]=a[i]%2;
			a[i]/=2;
		}
		a[i]=0;
		for(long long j=x;j>=1;j--)
		{
			a[i]=a[i]*10+b[j];
		}
	}
	for(long long j=1;j<n;j++)
	{
		ans=0;
		for(long long i=1;i<=n;i++)
		{
			m=yh(m,a[i]);
			if(m==k)
			{
				m=0;
				ans++;
			}
		}
		if(ans>mx)
		{
			mx=ans;
		}
	}
	cout<<mx;
	return 0;
}