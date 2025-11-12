#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005];
int xorr(int x,int y)
{
	int f[10],g[10],p=0,q=0,t=0,h=1;
	while(x!=0)
	{
		p++;
		f[p]=x%2;
		x/=2;
	}
	while(y!=0)
	{
		q++;
		g[q]=y%2;
		y/=2;
	}
	if(p<q)
	{
		for(int i=1;i<=p;i++)
		{
			if(f[i]==g[i])
			{
				g[i]=0;
			}
			else
			{
				g[i]=1;
			}
		}
		for(int i=1;i<=q;i++)
		{
			t+=g[i]*h;
			h*=2;
		}
	}
	else
	{
		for(int i=1;i<=q;i++)
		{
			if(f[i]==g[i])
			{
				f[i]=0;
			}
			else
			{
				f[i]=1;
			}
		}
		for(int i=1;i<=p;i++)
		{
			t+=f[i]*h;
			h*=2;
		}
	}
	return t;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,b,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		a[i]=xorr(a[i-1],b);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j>=0;j--)
		{
			if(c[j+1]==1)
			{
				break;
			}
			else if(xorr(a[i],a[j])==m)
			{
				c[i]=1;
				s++;
				break;
			}
		}
	}
	cout<<s;
	return 0;
}