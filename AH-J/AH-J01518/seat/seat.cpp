#include<bits/stdc++.h>
using namespace std;
long long a[200];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,i,s=0,x,y;
	cin>>n>>m;
	for(i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(i=2;i<=n*m;i++)
	{
		if(a[i]>a[1]) s++;
	}
	s++;
	if(s%n==0)
	{
		x=s/n;
		if(x%2==1)
		{
			y=n;
		}
		else
		{
			y=1;
		}
	}
	else
	{
		x=s/n+1;
		if(x%2==1)
		{
			y=s%n;
		}
		else
		{
			y=n-s%n+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
