#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],x,c,r;
bool cmp(int l,int r)
{
	return l>r;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++)
	{
		cin >> a[i];
	}
	x=a[1];
	int k;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
	{
		if (a[i]==x)
		{
			k=i;
			break;
		}
	}
	if (k%n==0)
	{
		c=k/n;
	}
	else
	{
		c=k/n+1;
	}
	k=k-(c-1)*n;
	if (c%2==0)
	{
		r=n-k+1;
		cout << r << endl;
	}
	else
	{
		r=k;
	}
	cout << c << " " << r;
	return 0;
}
