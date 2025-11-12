#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out" , "w",stdout);
	int t , n , m , p , h , l;
	int num = 1;
	cin >> n >> m;
	int a[105];
	t = n * m;
	for (int i = 1 ; i <= t ; i++)
	{
	cin >> a[i];
	}
	p = a[1];
	for (int i = 1 ; i <= t ; i++)
	{
		if (a[i] > p)
		{
			num++;
		}
	}
	if (num % n == 0)
	{
		l = num / n; 
	}
	else
	{
		l = num / n + 1; 
	}
	if (l % 2 == 0)
	{
		h = n - (num - 1) % n;
	} 
	else if (l % 2 == 1)
	{
		if (l = 1)
		{
			h = num;
		}
		else
		{
		h = num % n;
		}
	}
	cout << l  << " " << h;
	return 0;
}