#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s,b;
/*int e(int g)
{
	long long c=0;
	int i=10;
	while()
	{
		int aa=g%2;
		c=2*k/10;
	}
}
long long x(long long x,long long y)
{
	x=e(x);
	y=e(y);
	long long i=10;
	long long c=0;
	while(1)
	{
		long long k=x%i/(i/10);
		long long l=y%i/(i/10);
		if(k!=l)
		c+=(k/10);
	}
	c=ue(c);
	return c;
}*/
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++)
	{
		b=a[i];
		if(a[i]==k)
		{
			s++;
			
		}
		for(long long j=i+1;j<=n;j++)
		{
			b=b^a[j];
			//b=x(b,a[j]);
			cout<<b;
			if(b==k)
			{
				s++;
				break;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}

