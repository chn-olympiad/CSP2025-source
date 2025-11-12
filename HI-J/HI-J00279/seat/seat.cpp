#include<bits/stdc++.h>
using namespace std;
int x,a[10005],m,n,y; 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m*n;i++)
	{
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+m*n+1);
	for (int i=1;i<=m*n;i++)
	{
		if (a[i]==x)
		{
			y=i;
		}
	}
	y=n*m-y+1;
	if (y%n==0)
	{
		cout<<y/n<<" ";
		cout<<n;
	}
	else
	{
		cout<<y/n+1<<" ";
		cout<<y%n;
	}
	return 0;
} 
