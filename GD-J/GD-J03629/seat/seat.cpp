#include<bits/stdc++.h>
using namespace std;
int n,m,a1[101],a[101],p,q,x,y;
int main()
{
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	cin>>n>>m;
	q=n*m;
	cin>>p;
	a1[1]=p;
	for(int i=2;i<=q;i++)
	{
		cin>>a1[i];
	}
	int mid=0;
	sort(a1+1,a1+q+1);
	for(int i=q;i>0;i--)
	{
		mid++;
		a[mid]=a1[i];
	}
	int l=1,r=q;
	mid=(r-l)/2+1;
	while(a[mid]!=p)
	{
		if(a[mid]>p)
		{
			l=mid;
			mid=(r-l)/2+l;
		}
		else if(a[mid]<p)
		{
			r=mid;
			mid=(r-l)/2+l;
		}
	}
	if(q%mid!=0)
	{
		x=mid/n+1;
	}
	else
	{
		x=mid/n;
	}
	if(x%2==1)
	{
		y=mid%n;
		if(y==0)
		{
			y=n;
		}
	}
	else
	{
		y=n-mid%n+1;
		if(y==n+1)
		{
			y=1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
