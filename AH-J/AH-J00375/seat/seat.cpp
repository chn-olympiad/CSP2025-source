#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int a[100];
	int b;
	int c,r;
	cin >> n >> m;
	for(int i = 0; i < n * m; i ++)
	{
		cin >> a[i];
		b = a[0];
	}
	sort(a,a[n*m]);
	for(int i = 0;i < n * m; i++)
	{
		if(b==a[i])
		b = i;
	}
	if(b<=n)
	{
		c = b;
		r = 1;
	}
	else 
	{
		r = b / n + 1;
		if(r%2==0)
		{
			c = n-(b % n - 1);
		}
		else
		{
			if(b%n == 0)
				c = n;
			else c = b % n;
		}
	}
	cout << r << c;
	return 0;
}
