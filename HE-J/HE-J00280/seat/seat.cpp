#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=500;
int a[N],n,m,x,pos,r,c;
bool cmp(int a,int b)
{
	return a>b;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	x=a[1];
	for (int i=2;i<=n*m;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			pos=i;
			break;
		}
	}
	if (pos%n==0)
	{
		if ((pos/n)%2==0)
		{
			r=1;
			c=pos/n;
		}
		else 
		{
			r=n;
			c=pos/n;
		}
	}
	else
	{
		if ((pos/n+1)%2==0)
		{
			c=pos/n+1;
			r=n-pos%n+1;
		}
		else 
		{
			c=pos/n+1;
			r=pos%n;
		}
	}
	cout << c << " " << r;
	return 0;
}
