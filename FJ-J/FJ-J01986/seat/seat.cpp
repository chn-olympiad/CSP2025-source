#include <bits/stdc++.h>

using namespace std;

int n, m, arr[200];

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n * m; ++i)
	{
		cin >> arr[i];
	}
	
	int r = arr[1], id = 0;
	
	sort(arr + 1, arr + n * m + 1, cmp);
	
	for (int i = 1; i <= n * m; ++i)
	{
		if (arr[i] == r)
		{
			id = i;
			
			break;
		}
	}
	
	int c = id / n;
	
	if (id % n != 0)
	{
		++c;
	}
	
	if (c % 2 != 0)
	{
		r = id % n;
		
		if (r == 0)
		{
			r = n;
		}
	}
	else
	{
		r = n + 1 - id % n;
		
		if (id % n == 0)
		{
			r = 1;
		}
	}
	
	cout << c << " " << r;
}
