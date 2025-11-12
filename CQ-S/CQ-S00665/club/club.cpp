#include <bits/stdc++.h>
using namespace std;
int t;
long long n;
int maxn(int a, int b, int c)
{
	int m=0,x=0,y=0,z=0;
	if (x + 1 <= n /2 && a > b && a > c)
	{
		x += 1;
		m += a;
	}
	else if (y + 1 <= n /2 && b > a && b > c)
	{
		y += 1;
		m += b;
	}
	else
	{
		z += 1;
		m += c;
	}
	return m;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	for (int i = 0; i <= t; i++)
	{
		cin >> n;
		long long sum = 0;
		for (int j = 0; j < n; j++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			sum += maxn(a,b,c);
		}
		cout << sum << endl;
	}
	return 0;
}
