#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int a[500005],b[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,sum=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
		cin>>a[i];
		if(a[i]==k)
		{
			sum++;
		}
		while(a[i]!=0)
		{
			b[i]=b[i]*10+a[i]%2;
			a[i]=a[i]/2;
		}
		while(b[i]!=0)
		{
			a[i]=a[i]*10+b[i]%10;
			b[i]=b[i]/10;
		}
		b[i]=a[i];
	}
	int t=0,z=0,d=0,c=0;
	while(k!=0)
	{
		t=t*10+k%2;
		k=k/2;
	}
	while(t!=0)
	{
		k=k*10+t%10;
		t=t/10;
	}
	for(int i=1;i<=n-2;i++)
	{
		for(int j=i+1;j<=n-1;j++)
		{
			if(a[i]==k||a[i+1]==k)
			{
				j++;
				continue;
			}
			a[j+1]=a[j]+a[j+1];
			z=a[j+1];
			while(z!=0)
			{
				if((z%10)%2==0&&z%10!=0)
				{
					z-=2;
				}
				d=d*10+z%10;
				z=z/10;
			}
			while(d!=0)
			{
				c=c*10+d%10;
				d=d/10;
			}
			a[j+1]=c;
			c=0;
			if(a[j+1]==k)
			{
				sum++;
				j++;
			}
		}
		for(int j=1;j<=n;j++)
		{
			a[j]=b[j];
		}
	}
	cout<<sum;
    return 0;
}
