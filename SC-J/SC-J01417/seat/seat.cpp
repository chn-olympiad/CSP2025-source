#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
	{
		if(a[i]==s)
		{
			s=i;
			break;
		}
	}
	s=n*m-s+1;
	int y=s/n+1;
	if(s%n==0)
	{
		y--;
		if(y%2)
		{
			cout<<y<<" "<<n;
		}
		else
		{
			cout<<y<<" "<<1;
		}
	}
	else
	{
		if(y%2)
		{
			cout<<y<<" "<<s%n;
		}
		else
		{
			cout<<y<<" "<<n-s%n+1;
		}
	}
	
	return 0;
}