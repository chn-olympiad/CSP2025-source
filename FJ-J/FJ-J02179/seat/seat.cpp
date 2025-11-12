#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int xr=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xr)
		{
			xr=n*m-i+1;
			break;
		}
	}
	//for(int i=1;i<=n*m;i++)
		//cout<<a[i]<<" ";
	//cout<<endl<<xr;
	int c,r;
	c=ceil(double(double(xr)/double(n)));
	if(c==0)
		c=1;
	if(c%2==0)
		r=n-xr%n;
	else 
	{
		r=xr%n;
		if(r==0)
			r=n;
	}
	cout<<c<<" "<<r;  
	return 0;
}
