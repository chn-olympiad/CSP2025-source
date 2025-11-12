#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int h,l;
	cin>>h>>l;
	int n=h*l;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int b=a[0];
	sort(a,a+n);
	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==b)
		{
			break;
		}
	}
	i=n-1-i;
	int r=i%h;
	int c=(i-r)/h+1;
	if(c%2==1)
	{
		r=r+1;
	}
	else
	{
		r=h-r;
	}
	cout<<c<<' '<<r;
}
