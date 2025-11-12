#include <bits/stdc++.h>
using namespace std;

int arr[100];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m, c = 1, r = 1, tar;
	bool oper = true;
	
	cin >> n >> m;
	
	for (int i = 0; i < n * m; ++i)
	{
		cin >> arr[i];
	}
	
	tar = arr[0];
	
	sort(arr, arr + n * m, greater<int>());
	
	for (int i = 0; i < n * m; ++i)
	{
		if (arr[i] == tar)
		{
			break;
		}
		
		if (oper)
		{
			if (r == n)
			{
				++c;
				
				oper = false;
			}
			
			else ++r;
		}
		
		else
		{
			if (r == 1)
			{
				++c;
				
				oper = true;
			}
			
			else --r;
		}
	}
	
	cout << c << " " << r;
	
	return 0;
}
