#include<bits/stdc++.h>
using namespace std;
long long read()
{
	long long n1,x1=0,f=1;
	char c;
	c=getchar();
	while(c>'9'||c<'0')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c<='9'&&c>='0')
	{
		x1*=10;
		x1+=c-48;
		c=getchar();
	}
    return x1*f;
}
int n,m,a[1145140],sum=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	n=read();
	m=read();
	for(int z=1;z<=n*m;z++)
	{
		a[z]=read();
	}
	for(int z=2;z<=n*m;z++)
	{
		if(a[z]>a[1])
		{
			sum++;
		}
	}
	long long c=sum/n,h=sum%n;
	if(h!=0)
	{
		c++;
	}
	cout<<c;
	putchar(' ');
	if(c%2==0)
	{
		h=n-h-1;
	}
	if(h==0)
	{
		cout<<n;
	}
	else
	{
		cout<<h; 
	} 
	return 0;
}
