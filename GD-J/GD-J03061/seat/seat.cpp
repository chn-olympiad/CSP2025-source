#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r,r1,c,d;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	r=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m;j++)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			r1=i;
		}
	}
	if(r1%n==0) d=r1/n;
	else d=r1/n+1;
	if(d==1)
	{
		c=r1;
	}
	else if(d%2==1)
	{
		c=n*d-n-2;
	}
	cout<<d<<" "<<c;
	return 0;
}
