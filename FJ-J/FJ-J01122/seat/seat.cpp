#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],c,r;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1; i<=n*m; i++)
	{
		cin >> a[i];
	}
	int p=a[1],now=0;
	sort(a+1,a+n*m+1);
	for(int i=1; i<=n*m; i++)
	{
		if(a[i]==p)
		{
			now=i;
			break;
		}
	}
	now=n*m-now+1;
	int b=now%n,d=now/n;
	if(b!=0)
	{
		c=d+1;
	}
	else
	{
		c=d;
		b=n;
	}
	if(c%2==1)
	{
		r=b;
	}
	else
	{
		r=n-b+1;
	}
	cout << c << " " << r;
	return 0;
}
