#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s,j=1;
	cin>>s;
	for(int i=2;i<=m*n;i++)
	{
		int p;
		cin>>p;
		if(p>s)
		{
			j++;
		}
	}
	int l=0;
	if(j%n==0)
	{
		l=j/n;
	}
	else
	{
		l=j/n+1;
	}
	int p=j%n;
	cout<<l<<' ';
	if(l%2==0)
	{
		if(p==0)
		{
			cout<<1;
		}
		else
		{
			cout<<n-p+1;
		}
	}
	else
	{
		if(p==0)
		{
			cout<<n;
		}
		else
		{
			cout<<p;
		}
	}
	return 0;
}
