#include<bits/stdc++.h>
using namespace std;
int r,n,m,x;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	int sum=n*m;
	int a[105];
	for(int i=0;i<sum;i++)
	{
		cin >> a[i];
	}
	r=a[0];
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--)
	{
		if(a[i]==r)
		{
			x=sum-i;
		}
	}
	cout << x << " ";
	int c=(x-x%n)/n+1;
	int r;
	if(c%2==1)
	{
		r=x-(n*(c-1));
	}
	else
	{
		r=n+1-(x-(n*(c-1)));
	}
	cout << c << " " << r;
	return 0;
}
