#include<bits/stdc++.h>
using namespace std;
int a[205];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c=0,r=0;
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	int t=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			{
				swap(a[j],a[j+1]);
			}
		}
	}
	int z=0;
	for(int i=1;i<=n*m;i++)
	{
		if(t==a[i])
		{
			z=i;
		}
	}
	int k=z/m;
	if(z%m!=0)
	{
		int h=z%m;
		c=k+1;
		if(k%2==0)
		{
			r=h;
		}
		if(k%2==1)
		{
			r=n-h+1;
		}
	}
	else if(z%m==0)
	{
		c=k;
		if(c%2==0)
		{
			r=1;
		}
		if(c%2==1)
		{
			r=n;
		}
	}
	cout << c << " " << r;

	return 0;
}
