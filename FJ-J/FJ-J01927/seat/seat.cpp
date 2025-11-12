#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int s,mc;
int x;
int y;
bool cmp(int q,int p)
{
	if(q<p)
	{
		return 0;
	}
	return 1;
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
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==s)
		{
			mc=i;
		}
	}
	if(mc%n!=0)
	{
		y=(mc/n+1);
		if(y%2==1)
		{
			x=mc%n;
			cout<<y<<" "<<x;
			return 0;
		}
		else
		{
			x=n-mc%n+1;
			cout<<y<<" "<<x;
			return 0;
		}
	}
	else if(mc%n==0)
	{
		y=max(1,(mc/n));
		if(y%2==1)
		{
			x=n;
			cout<<y<<" "<<x;
			return 0;
		}
		else
		{
			x=1;
			cout<<y<<" "<<x;
			return 0;
		}
	}
}
