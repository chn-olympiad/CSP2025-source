#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, m, a[105], num;
bool cmp(int p, int q)
{
	return p > q;
}
signed main()
{
	/*
	freopen("seat.in", "r", "std::cin");
	freopen("seat.out", "w", "std::cout");
	*/
	cin >> n >> m;
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	num = a[1];
	sort(a + 1, a + (n * m) + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		if (a[i] == num)
		{
			num = i;
			break;
		}
	}
	cout << ceil((num * 1.0) / n) << " ";
	if ((int)ceil((num * 1.0) / n) % 2 == 1)
	{
		if (num % n == 0)
		{
			cout << n;
		}
		else
		{
			cout << num % n;
		}
	}
	else
	{
		
		cout <<  n - (num % n) + 1;
	}
	return 0;
	
	
}
