#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[105];
int c,r;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int R = a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i = 1;i<=n*m;i++)
	{
		if(a[i] == R)
		{
			R = i;
		}
		
	}
	if(R<=n)
	{
		c = 1;
	}
	else
	{
		c = (R+n-1)/n;
	}
	if(c&1 == 1)
	{
		if(R%n == 0)
		{
			r = n;
		}
		else
		{
			r = R%n;
		}
	}
	else
	{
		if(R%n == 0)
		{
			r = 1;
		}
		else
		{
			r = (n+1)-R%n;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}
