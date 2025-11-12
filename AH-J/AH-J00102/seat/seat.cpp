#include<bits/stdc++.h>
using namespace std;
long long n,m,l,q;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	l=a[1];
	sort(a+1,a+n*m+1);
	int j=1;
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==l)
		{
			q=j;
			break;
		}
		j++;
	}
	long long x,y;
	if(q%n==0)
	{
		x=q/n;
	}
	else
	{
		x=q/n+1;
	}
	if(q%n==0)
	{
		q=n;
	}
	else
	{
		q=q%n;
	}
	if(x%2!=0)
	{
		y=q;
	}
	else
	{
		y=n-q+1;
	}
	cout<<x<<" "<<y;
}
