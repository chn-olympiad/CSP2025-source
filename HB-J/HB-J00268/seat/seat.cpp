#include <bits/stdc++.h>
using namespace std;

bool cmp(int x, int y)
{
	return x > y;
}

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	int arr[105] = {};
	
	for(int i = 1; i <= (n * m); i++)
		cin >> arr[i];
		
	int targetNum = arr[1];
	
	sort(arr + 1, arr + n * m + 1, cmp);
	
	int target_id = 0;
	
	for(int i = 1; i <= (n * m); i++)
		if(arr[i] == targetNum)
		{
			target_id = i;
			break;
		}
			
	int lessNum = target_id % (2 * n);
	int timesNum;
	
	for(int i = 0; i <= target_id; i++)
		if(i * 2 * n > target_id)
		{
			timesNum = i - 1;
			break;
		}

	int x, y;
	
	if(lessNum == 0)
		x = 2 * timesNum;
		
	else if(lessNum != 0)
		x = 2 * timesNum + 1;
		
	if(lessNum > 0 and lessNum <= n)
		y = lessNum;
		
	else
	{
		if(lessNum > n and lessNum < (2 * n))
		{
			y = (2 * n) + 1 - lessNum;
			x ++;
		}
			
		else if(lessNum == 0)
			y = 1;
	}
	
	cout << x << " " << y;

	return 0;
}
