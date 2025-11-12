#include <bits/stdc++.h>
using namespace std;
int n,a[10000],b,c,d;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		b+=a[i];
		if (a[i]>c)
		{
			c=a[i];
		}
	}
	
	if (n>=3&&b>2*c)
	  {
		d++;
	  }
	cout<<d;
	return 0;
}
