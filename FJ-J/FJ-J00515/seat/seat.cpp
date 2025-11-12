#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,a,x;
	cin >> n >> m;
	int num[1000];
	for (int i=0;i<n*m;i++)
	{
		cin >> num[i];
	}
	a = num[0];
	sort(num,num+n*m);
	for (int i=0;i<n*m;i++)
	{
		if (num[i] == a)
		{
			x = n*m - i;
		}
	}
	if (x%n==0)
	{
		cout << x/n << ' ';
	}
	else
	{
		cout << x/n+1 << ' ';
	}
	if (x % n == 0)
	{
		cout << n;
	}
	else if ((x/n)%2==1)
	{
		cout << n-x%n+1;
	}
	else
	{
		cout << x%n;
	}
	return 0;
}
