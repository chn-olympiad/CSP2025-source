#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[107];
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+1+n*m);
	int k;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==p)
		{
			k=n*m-i+1;
			continue;
		}
	}
	int u=n*m;
	int x=1,y=1;
	int sum=1;
	while(u--)
	{
		if(x%2!=0&&y>0)
		{
			y++;
		}
		if(x%2==0)
		{
			y--;
		}
		if(y==n+1)
		{
			x++;
			y--;
		}
		if(y==0)
		{
			x++;
			y++;
		}
		sum++;
		if(sum==k)
		{
			
			cout<<x<<' ';
			cout<<y;
			return 0;
		}
	}
	return 0;
}
	
