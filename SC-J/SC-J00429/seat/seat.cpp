#include<bits/stdc++.h>
using namespace std;
int  n,m,j=0;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+2,a+1+n*m);
	for(int i=n*m;i>=2;i--)
	{
		if(a[i]>a[1])
		{
			j++;
		}
	}
	int x=0,y=0,k=0,p=0;
	k=j%n;
	p=j/n;
	if(k==0)
	{
		if(p%2==0)
		{
			x=p+1;
			y=1;
			cout<<x<<' '<<y;
			return 0;
		}
		else
		{
			x=p+1;
			y=n;
			cout<<x<<' '<<y;
			return 0;
		}
	 } 
	else
	{
		if(p%2==0)
		{
			x=p+1;
			y=k+1;
			cout<<x<<' '<<y;
			return 0;
		}
		else
		{
			x=p+1;
			y=n-k;
			cout<<x<<' '<<y;
			return 0;
		}
	}
	return 0;
}
