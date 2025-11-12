#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
int a[1005];
int t;
int x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==k)
		{
			t=n*m-i+1;
		}
	}
	if(t%n==0)
	{
		x=t/n;
	}
	else
	{
		x=t/n+1;
	}
	if(t%n==0)
	{
		y=n;
	} 
	else
	{
		y=t%n-1;
	}
	if(x%2==0)
	{
		cout<<x<<" "<<n-y;
	}
	else
	{
		cout<<x<<" "<<y;
	}
	return 0;
}
