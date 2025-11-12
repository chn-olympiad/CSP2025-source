#include<bits/stdc++.h>
using namespace std;

int n, m, num, cnt = 1, arr[150];

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	num = n * m;
	for(int i = 1; i <= num; i++)
	{
		cin >> arr[i];
		if(i >= 2)
		{
			if(arr[i] > arr[1])
			{
				cnt++;
			}
		}
	}
	
	int x = (cnt / m), y = cnt % m;
	if(cnt % m != 0) x++;
	if(y == 0) y = m;
	
	if(x % 2 == 0)
	{
		y = m - y + 1;
	}
	
	cout << x << " " << y;
	return 0;
}
