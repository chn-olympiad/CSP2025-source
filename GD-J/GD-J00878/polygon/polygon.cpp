#include<bits/stdc++.h>
using namespace std;
int a[10010];
int p3(int a,int b,int c)
{
	int p=-1;
	p=max(a,p);
	p=max(b,p);
	p=max(c,p);
	return ((a+b+c)>(2*p));
}
int p4(int a,int b,int c,int d)
{
	int p=-1;
	p=max(a,p);
	p=max(b,p);
	p=max(c,p);
	p=max(d,p);
	return ((a+b+c+d)>(2*p));
}
int p5(int a,int b,int c,int d,int e)
{
	int p=e;
	return ((a+b+c+d+e)>(2*p));
}
int p6(int a,int b,int c,int d,int e,int f)
{
	int p=f;
	return ((a+b+c+d+e+f)>(2*p));
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,u=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==3)
	{
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
	}
	else if(n==4)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					u+=p3(a[i],a[j],a[k]);
				}
			}
		}
		u+=p4(a[1],a[2],a[3],a[4]);
		cout<<u;
	}
	else if(n==5)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					u+=p3(a[i],a[j],a[k]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						u+=p4(a[i],a[j],a[k],a[l]);
					}
				}
			}
		}
		u+=p5(a[1],a[2],a[3],a[4],a[5]);
		cout<<u;
	}
	else if(n==6)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					u+=p3(a[i],a[j],a[k]);
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						u+=p4(a[i],a[j],a[k],a[l]);
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j+1;k<=n;k++)
				{
					for(int l=k+1;l<=n;l++)
					{
						for(int o=l+1;o<=n;o++)
					{
						u+=p5(a[i],a[j],a[k],a[l],a[o]);
					}
					}
				}
			}
		}
		u+=p6(a[1],a[2],a[3],a[4],a[5],a[6]);
		cout<<u;
	}
	return 0;
 } 
