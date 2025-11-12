#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int c,r;
	cin >> m >>n;
	for(int i=1;i<=n*m;i++)
	{
		int  a[i];
		cin >> a[i];	
		if(a[1]<a[n])
		{
			c=1;
			r=n;
		}
		if(a[1]<a[n+1]&&a[1]>a[2*n])
		{
			c=2;
			r=n;
		}
		if(a[1]<a[2*n]&&a[1]<a[n*m])
		{
			c=2;
			r=1;
		}
		if(a[1]<a[2*n+1])
		{
			c=3;
			r=1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
