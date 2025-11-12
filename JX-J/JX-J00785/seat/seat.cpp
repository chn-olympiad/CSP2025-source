#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int c=1;
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			c++;
		}
	}
	int l,h;
	l=(c-1)/n+1;
	if(l%2==1)
	{
		h=(c-1)%n+1;
	}
	else
	{
		h=n-(c-1)%n;
	}
	cout<<l<<" "<<h;
	return 0;
}
