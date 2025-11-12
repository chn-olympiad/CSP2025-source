#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o=1,x=0;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
	}
	x=a[0];
	for(int i=1;i<n*m;i++)
	{
		if(a[i]>x)
		{
			o++;
		}
	}
	if((o/m)%2==1)
	{
		if(o%m==0)
		{
			cout<<o/m<<" "<<n;
		}
		else
		{
			cout<<(o+n)/m<<" "<<o%n+1;
		}
	}
	if((o/m)%2==0)
	{
		if(o%m==0)
		{
			cout<<o/m<<" "<<1;
		}
		else
		{
			cout<<(o+n)/m<<" "<<(o+n)/m-n+1;
		}
	}
	return 0;
 } 
 
