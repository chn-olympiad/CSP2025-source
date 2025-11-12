#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long a[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,y,t;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	y=a[1];
	for(int i=1;i<=n*m;i++)
	{
		for(int j=1;j<n*m;j++)
		{
			if(a[j]<a[j+1])
			{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;}
		}
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==y)
		{
		y=i;
		if(((y-1)/n+1)%2==1)
		{
			cout<<((y-1)/n)+1<<' '<<(y-1)%n+1;
		}
		else
		{
			cout<<((y-1)/n)+1<<' '<<(n+1)-((y-1)%n+1);
		}
		}
	}
	return 0;
}
