#include<bits/stdc++.h>
using namespace std;
int a[105],x=1,y=0,p,j;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			p=a[i];
		}
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==p)
		{
			j=n*m-i+1;
			break;
		}
	}
	for(int i=1;i<=j;i++)
	{
		if(x%2==1&&y==n)
		{
			x++;
		}
		else if(x%2==1&&y<n)
		{
			y++;
		}
		else if(x%2==0&&y==1)
		{
			x++;
		}
		else if(y<n)
		{
			y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
