#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105],x,y,num=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==num)num=n*m-i+1;
	}
	if(num%n==0)
	{
		x=num/n;
		y=n;
	}
	else
	{
		x=num/n+1;
		if(x%2==0)
		{
			y=n-num%n+1;
		}
		else
		{
			y=num%n;
		}
	}
	cout<<x<<" "<<y;
	return 0;
 } 
