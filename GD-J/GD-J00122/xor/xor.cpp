#include<bits/stdc++.h>
using namespace std;
long long a[500000+5],k,n,m,t,p,q,c[500000+5],g[5000],h[5000],e;
int f(int x)
{
	int b[1000],o=0,v=0;
	while(x>0)
	{
		b[++o]=x%2;
		x/=2;
	}
	for(int i=o;i>=1;i--)
	v=v*10+b[i];
	return v;
}
int r(int x,int y)
{
	int b[1000],o=0,v=0,u=1;
	while(x>0||y>0)
	{
		if(x>0&&y>0)
		{
			if(x%10==y%10)
			b[++o]=0;
			else b[++o]=1;
		}
		if(x==0)
		b[++o]=y%10;
		if(y==0)
		b[++o]=x%10;
		x/=10;
		y/=10;
	}
	for(int i=1;i<=o;i++)
	{
		v+=b[i]*u;
		u*=2;
	}
	return v;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=f(a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)
			{
				if(a[i]==m)
				{
					e++;
					g[e]=i;
					h[e]=j;
					t++;
				}
			}	
			else
			{
				p=c[i];
				for(int l=i+1;l<=j;l++)
				{
					q=r(p,c[l]);
					p=f(q);
				}
				if(q==m)
				{
					e++;
					g[e]=i;
					h[e]=j;
					t++;
				}
			}
		} 
	}
	for(int i=1;i<=e;i++)
	{
		for(int j=i;j<=e;j++)
		{
			if(i!=j)
			{
				if(g[j]<=g[i]&&h[j]>=h[i])
				t--;
				if(g[i]<=g[j]&&h[i]>=h[j])
				t--;
			}
		}
	}
	cout<<t;
	return 0;
}
