#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y)
{
	return x>y;
} 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>a[1];
	int q=a[1];
	for (int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==q)
		{
			q=i;
			break;
		}
	}
	int c=q/n;
	if (q%n==0)
	{
		cout<<c<<" ";
	}
	else
	{
		c++; 
		cout<<c<<" ";
	}
	int r=q%n; 
	if (c%2==1)
	{
		if (r==0)
		{
			cout<<n;
		}
		else
		{
			cout<<r;
		}
	}
	else
	{
		if (r==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n-r+1;
		}
	}
	return 0;
}
