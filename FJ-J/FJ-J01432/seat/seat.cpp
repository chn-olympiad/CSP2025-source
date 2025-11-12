#include <bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sk;
	cin >> n >> m;
	for(int i = 1;i <= n*m;i++)
	{
		cin >> a[i];
	}
	sk = a[1];
	sort(a+1,a+n+1,cmp);
	int i = 1;
	while(a[i] >= sk)
	{
		i++;
	}
	if(n == 1)
	{
		if(m == 1)
		{
			cout << "1 1";
			return 0;
		}
		else
		{
			cout << i-1 << " 1";
			return 0;
		}
	}
	if(m == 1)
	{
		cout << "1 " << i-1;
		return 0;
	}
	int c,r;
	if(i % n == 0)
	{
		c = (i - 1) / n + 1;
	}
	else
	{
		c = i / n + 1;
	}
	cout << c << " ";
	if(c % 2 == 0)
	{
		r = (n - i % n) + 1;
		if(i % n == 0)
		{
			r = 1;
		}
	}
	else
	{
		r = i % n - 1;
		if(i % n == 0)
		{
			r = n;
		}
	}
	cout << r;
	
	return 0;
}
