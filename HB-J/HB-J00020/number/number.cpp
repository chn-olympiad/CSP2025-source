#include<bits/stdc++.h>
using namespace std;
int n,m,r;
int main()
{
	cin>>n>>m;
	int a[n*m]={};
	for(int i=0;i<=n*m-1;i++)
	{
		cin>>a[i];
	}
	r=a[0];
	for(int i=0;i<=n*m;i++)
	{
		for(int j=i+1;j<=n*m-1;j++)
		{
			if(a[i]<a[j])
			{
				int y=a[i];
				a[i]=a[j];
				a[j]=y;
			}
		}
	}
	int l;
	for(int i=0;i<=n*m-1;i++)
	{
		if(a[i]==r)
		{
			l=i+1;
		}
	}
	cout<<1+(l%n)<<' '<<m+(l%m);
	return 0;
}
