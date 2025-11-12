#include<bits/stdc++.h>
using namespace std;
int a[120];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int h=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=i+1;j<=m*n;j++)
		{
			if(a[i]<a[j])
			{
				swap(a[i],a[j]);
			}
		}
	}
	int o;
	for(int i=1;i<=m*n;i++)
	{
		if(a[i]==h)
		{
			o=i;
		}
	}
	int c,p;
	c=o/n+1;
	p=o%n;
	if(p==0)
	{
		p=m;
	}
	cout<<c<<" ";
	if(c%2==1)
	{
		cout<<p;
	}
	else
	{
		cout<<m-p+1;
	}
	return 0;
}
