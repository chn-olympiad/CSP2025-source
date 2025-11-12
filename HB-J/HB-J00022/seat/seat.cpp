#include<bits/stdc++.h>
using namespace std;
int n,m,k,x,c=1,y,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>k;
	for(int i=1;i<n*m;i++)
	{
		cin>>x;
		if(k<x)
		{
			c++;
		}
	}
	x=1,y=1,d=1;
	for(int i=1;i<c;i++)
	{
		if(x%2==1&&y==m)
		{
			x++;
			d=-1;
		}
		else if(x%2==0&&y==1)
		{
			x++;
			d=1;
		}
		else
		{
			y+=d;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
