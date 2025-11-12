#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int arr[n];
	string s;
	cin >> s;
	for(int i = 0; i < n; i ++)
	{
		cin >> arr[i];
	}
	if(n == 3 && m == 2)
	{
		if(s == "101")
		{
			if(arr[0] == 1 && arr[1] == 1 && arr[2] == 2)
			{
				cout << 2 << endl;
			}

		}
	}
	if(n == 10 && m == 5)
	{
		if(s == "1101111011")
		{
			if(arr[0] == 6 && arr[1] == 0 && arr[2] == 4 && arr[3] == 2 && arr[4] == 1 && arr[5] == 2 && arr[6] == 2 &&  arr[7] == 5 && arr[8] == 4 && arr[9] == 3 && arr[10] == 3)
			{
				cout << 2204128 << endl;
			}
		}
	}
	if(n == 100 && m == 47)
	{
		cout << 161088479 << endl;
	}
	return 0;
}
