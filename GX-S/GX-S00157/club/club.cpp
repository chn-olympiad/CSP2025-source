#include<bits/stdc++.h>
using namespace std;
int o=0,l=0;
int a[100006][6];
int m(int z,int b,int c,int n,long long r)
{
	int q=0,w=0,e=0;
	q=a[n][1];
	w=a[n][2];
	e=a[n][3];
	if(n>o+1)
	{
		return r;
	}
	n+=1;
	long long y=0,u=0,x=0;
	z+=1;
	if(z<=l)
	y=m(z,b,c,n,r+q);
	z-=1;
	b+=1;
	if(b<=l)
	u=m(z,b,c,n,r+w);
	b-=1;
	c+=1;
	if(c<=l)
	x=m(z,b,c,n,r+e);
	if(y>=u)
	{
		if(y>=x)
		{
			return y;
		}
		else
		{
			return x;
		}
	}
	else
	{
		if(u>=x)
		{
			return u;
		}
		else
		{
			return x;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int s=1;s<=t;s++)
	{
		cin>>o;
		
		for(int i=1;i<=100000;i++)
		{
			a[i][1]=0;
			a[i][2]=0;
			a[i][3]=0;
		}
		for(int i=1;i<=o;i++)
		{
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(o>11)
		{
			long long r=0;
			for(int j=1;j<=3;j++)
			for(int i=1;i<o;i++)
			{
				if(a[i][1]<a[i+1][1])
				{
					int u=a[i][1];
					a[i][1]=a[i+1][1];
					a[i+1][1]=u;
				}
			}
			for(int i=1;i<o/2;i++)
			{
				r+=a[i][1];
			}
			cout<<r<<endl;
		}
		else
		{
		l=o/2;
		cout<<m(0,0,0,1,0)<<endl;
	}
	}
	return 0;
}
