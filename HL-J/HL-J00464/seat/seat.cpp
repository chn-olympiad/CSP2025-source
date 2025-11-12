#include<bits/stdc++.h>
using namespace std;
int a[1010];
int b[1010];
int main()
{	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,nm,w=0,d;
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=0;i<nm;i++)
	{
		scanf("%d",&a[i]);
	}
	int zz=a[0];
	sort(a,a+nm);
	for(int i=nm-1;i>=0;i--)
	{
		if(a[i]>=0)
		{
			b[w]=a[i];
			w++;
		}
	}
	for(int i=0;i<nm;i++)
	{
		if(b[i]==zz)
		{
			d=i+1;
		}
	}
	int f=0;
	for(int i=1;i<=m;i++)
	{
		if(f==0)
		{
			for(int j=1;j<=n;j++)
			{
				d-=1;
				if(d<=0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			f=1;
		}
		else
		{	for(int j=n;j>=1;j--)
			{
				d-=1;
				if(d<=0)
				{
					cout<<i<<" "<<j;
					return 0;
				}
			}
			f=0;
		}
	}
	return 0;
}
