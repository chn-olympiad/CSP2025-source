#include <iostream>
#include <algorithm>
using namespace std;
int n,m,k,rc,t,a[105],x,y;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	k=n*m;
	for (int i=1;i<=k;i++)
	{
		cin >> a[i];
	}
	rc=a[1];
	sort (a+1,a+k+1,cmp);
	for (int i=1;i<=k;i++)
	{
		if (a[i]==rc)
		{
			t=i;
			break;
		}
	}
	x=(t+n-1)/n;
	if (x%2==1)
	{
		y=t-n*(x-1);
	}
	else
	{
		y=n-t%n+1;
	}
	cout << x << " " << y;
	return 0;
}
