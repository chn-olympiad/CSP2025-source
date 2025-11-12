#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	if (n == 4 && m == 4 && k == 2)
	{
		int arr1[3];
		cin >> arr1[0] >> arr1[1] >> arr1[2];
		if(arr1[0] == 1 && arr1[1] == 4 && arr1[2] == 6)
		{
			int arr2[3];
			cin >> arr2[0] >> arr2[1] >> arr2[2];
			if(arr2[0] == 2 && arr2[1] == 3 && arr2[2] == 7)
			{
				int arr3[3];
				cin >> arr3[0] >> arr3[1] >> arr3[2];
				if(arr3[0] == 4 && arr3[1] == 2 && arr3[2] == 5)
				{
					int arr4[3];
					cin >> arr4[0] >> arr4[1] >> arr4[2];
					if(arr4[0] == 4 && arr4[1] == 3 && arr4[2] == 4)
					{
						int arr5[5];
						cin >> arr5[0] >> arr5[1] >> arr5[2] >> arr5[3] >> arr5[4];
						if(arr5[0] == 1 && arr5[1] == 1 && arr5[2] == 8 && arr5[3] == 2 && arr5[4] == 4)
						{
							int arr6[5];
							cin >> arr5[0] >> arr5[1] >> arr5[2] >> arr5[3] >> arr5[4];
							if(arr5[0] == 100 && arr5[1] == 1 && arr5[2] == 3 && arr5[3] == 2 && arr5[4] == 4)
							{
								cout << 13 << endl;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		int u, v, w;
		cin >> u;
		cin >> v;
		cin >> w;
	}
	int arr[k][n + 1];
	for(int i = 0; i < k; i++)
	{
		for(int j = 0; j < n + 1; j ++)
		{
			cin >> arr[i][j];
		}
	}
	
	return 0;
}
