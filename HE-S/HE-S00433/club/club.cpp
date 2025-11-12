#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int t;
	cin >> t;
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	for(int i = 0; i < t; i ++)
	{
		int n;
		cin >> n;
		int res = 0;
		int max1 = 0, max2 = 0, max3 = 0;
		for(int j = 0; j < n; j ++)
		{
			int arr[3];
			cin >> arr[0];
			cin >> arr[1];
			cin >> arr[2];
			if(arr[0] > arr[1] && arr[0] > arr[2])
			{
				if(max1 < n / 2)
				{
					max1++;
					res += arr[0];
				}
				else
				{
					if(arr[1] > arr[2] && max2 < n /2)
					{
						max2 ++;
						res += arr[1];
					}
					else
					{
						max3 ++;
						res += arr[2];
					}
				}
			}
			if(arr[0] < arr[1] && arr[0] < arr[2])
			{
				if(arr[1] > arr[2] && max2 < n / 2)
				{
					max2 ++;
					res += arr[1];
				}
				else
				{
					if((arr[1] < arr[2] && max2 < n / 2) || (max2 > n / 2))
					{
						max3 ++;
						res += arr[2];
					}
					else
					{
						max1++;
						res += arr[0];
					}
				}
			}
			if(arr[0] < arr[1] && arr[0] > arr[2])
			{
				if(max2 < n / 2)
				{
					res += arr[1];
					max2++;
				}
				else
				{
					if(max1 < n /2)
					{
						max1 ++;
						res += arr[0];
					}
					else
					{
						max3 ++;
						res += arr[2];
					}
				}
			}
			if(arr[0] > arr[1] && arr[0] < arr[2])
			{
				if(max3 < n / 2)
				{
					res += arr[2];
					max3++;
				}
				else
				{
					if(max1 < n /2)
					{
						max1 ++;
						res += arr[0];
					}
					else
					{
						max2 ++;
						res += arr[1];
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}
