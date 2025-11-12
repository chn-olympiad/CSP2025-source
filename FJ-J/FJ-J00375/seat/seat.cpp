#include<bits/stdc++.h>
using namespace std;
int n,m,a[101],sum=1,l,h;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[n*(i-1)+j];
			if(a[n*(i-1)+j]>a[1])
			{
				sum++;
			}
		}
	}
	l=(sum-1)/n+1;
	if(l%2==0)
	{
		h=n-(sum-(l-1)*n)+1;
	}
	else
	{
		h=sum-(l-1)*n;
	}
	cout<<l<<" "<<h;
	return 0;
} 
