#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	long long t=1;
	for(long long i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		{
			t++;
		}
	}
	long long c,r;
	c=(t-1)/n+1;
	r=(t-1)%n+1;
	if(c%2==0)
	{
		r=n-r+1;
	}
	cout<<c<<" "<<r;
	return 0;
}
