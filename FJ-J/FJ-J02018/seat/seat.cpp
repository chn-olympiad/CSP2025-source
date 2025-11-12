#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[101];
int cmp(int x,int y)
{
	return y<x; 
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int o=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==o)
		{
			x=i;
			break;
		}
	}
	if(x%n==0)
	{
		int y=x/n;
		if(y%2==0)
		{
			cout<<y<<" "<<1;
		}
		else
		{
			cout<<y<<" "<<n;
		}
	}
	else
	{
		int z=x%n;
		int u=x/n;
		if(u%2==0)
		{
			cout<<u+1<<" "<<z;
		}
		else
		{
			cout<<u+1<<" "<<n+1-z;
		}
	}
	return 0;
} 
