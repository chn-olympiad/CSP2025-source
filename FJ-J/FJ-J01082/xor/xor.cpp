//异乡的旅行者啊，愿风神庇佑着你——BDFZ_lzq 
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
int n,k,sum=0,m;
int a[1145140];
bool b[1145140],op=1;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    n=read();
    k=read();
    for(int z=1;z<=n;z++)
    {
    	a[z]=read();
    	if(a[z]==k)
    	{
    		sum++;
    		b[z]=1;
		}
	}
	m=n;
	for(int z=1;z<=m;z++)
	{
		int lqy=0,hcc=0;
		for(int y=1;y<=n;y++)
		{
			if(b[y]!=1)
			{
				lqy++;
			}
			else
			{
				if(hcc<lqy)
				{
					hcc=lqy;
				}
				lqy=0;
			}
		}
        if(hcc<lqy)
    	{
			hcc=lqy;
		}
		m=hcc+1; 
		for(int y=1;y<=n-z+1;y++)
		{
			int temp=a[y];
			if(b[y]==1)
			{
				continue;
			}
			for(int cwy=y+1;cwy<=y+z-1;cwy++)
			{
				temp=(temp xor a[cwy]);
				if(b[cwy]==1)
				{
					temp=-91;
					break;
				}
			}
			if(temp==k)
			{
				sum++;
				for(int cwy=y;cwy<=y+z-1;cwy++)
				{
					b[cwy]=1;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
