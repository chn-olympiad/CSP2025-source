#include <iostream>
using namespace std;
int n,m,a[105],c,cnt,d;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	c=100-a[1];
	while (c>=0)
	{
		c=c-n;
		cnt++;
	}
	if ((100-a[1])<n)
	{
		d=(100-a[1])+1;
	}
	else
	{
		d=(100-a[1])%n+1;
	}
	if (c%2==0)
	{
		d=n-d+1;
	}
	cout<<cnt<<" "<<d;
	return 0;
}