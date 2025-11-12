#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x=n*m,b,y,c,r;
	int a[x];
	for(int i=0;i<x;i++)			
		cin>>a[i];
	b=a[0];
	sort(a,a+x);
	for(int i=1;i<=x;i++)
	{
		if(a[i-1]==b)
			y=x-i+1;
	}
	c=y/n;
	if(y%n!=0)
		c++;
	r=y%(2*n);
	if(r>n)
	{	
		r=n-r%n+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
