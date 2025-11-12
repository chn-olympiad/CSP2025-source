#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int l[501000];
int m[501000];
int p=0;
int mxor(int a,int b)
{
	int c[3][51]={};
	int d=50,e=50;
	while(a>0)
	{
		c[0][d]=a%2;
		a=a/2;
		d--;
	}
	while(b>0)
	{
		c[1][e]=b%2;
		b=b/2;
		e--;
	}
	int i=min(d,e);
	while(i<51)
	{
		if(c[1][i]!=c[0][i])
		{
			c[2][i]=1;
		}
		else
		{
			c[2][i]=0;
		}
	}
	int r=0;
	i=50;
	while(i>=min(d,e))
	{
		r+=pow(2,50-i);
	}
	return r;
}
int xor2(int c,int d,int e)
{
	int cc;
	if(c<d)
	{
		e=xor2(c+1,d,e);
	}
	cc=mxor(e,l[c]);
	return cc;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(l,-1,sizeof(l));
	int a;
	cin>>a;
	int bb;
	cin>>bb;
	for(int i=0;i<a;i++)
	{
		cin>>l[i];
	}
	memset(m,-1,a);
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<a-i;j++)
		{
			if(xor2(j,j+i,0)==bb)
			{
				int sp=0;
				for(int k=j;k<=j+i;k++)
				{
					if(m[k]==1)
					{
						sp=1;
						break;
					}
				}
				if(sp==1)
				{
					break;
				}
				else
				{
					for(int k=j;k<=j+i;k++)
					{
						m[k]=1;
					}	
				}
				p++;
			}
		}
	}
	cout<<p;
	return 0;
}