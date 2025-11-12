#include <bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
long long c[100005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long t,n,m;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
			cin>>b[j];
			cin>>c[j];
		}
		m=n/2;
	}
	for(int j=1;j<=m+1;j++)
	{
		int x=0;
		if(a[j]>a[j+1])
		{
			x=a[j+1];
			a[j+1]=a[j];
			a[j]=x;
		}
		int y=0;
		if(b[j]>b[j+1])
		{
			y=b[j+1];
			b[j+1]=b[j];
			b[j]=y;
		}
		int z=0;
		if(c[j]>c[j+1])
		{
			z=c[j+1];
			c[j+1]=c[j];
			c[j]=z;
		}
	}
	cout<<a[n]<<endl;
	cout<<b[n]<<endl;
	cout<<c[n]<<endl;
	return 0;
}
