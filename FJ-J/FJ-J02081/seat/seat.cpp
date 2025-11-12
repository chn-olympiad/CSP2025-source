#include<bits/stdc++.h>
using namespace std;
int a[100+10];
int main() 
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
	{
		cin>>a[i];
	}
	int s;
	s=a[1];
	sort(a+1,a+m*n+1);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]==s)
		{
			s=m*n-i+1;
			break;
		}
	}
	int x,y;
	if(s%n==0)
	{
		x=s/n;
		y=n;
	}
	else
	{
		x=s/n+1;
		y=s%n;
	}
	if(x%2==0)
	{
		cout<<x<<" "<<n-y+1;
	}
	else
	{
		cout<<x<<" "<<y;
	}
	return 0;
}
