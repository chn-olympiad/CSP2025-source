#include <algorithm>
#include <fstream>

using namespace std;

int n, m, a;
int arr[110];

ifstream cin("seat.in");
ofstream cout("seat.out");

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n * m; i++)
	{
		cin >> arr[i];
	}
	a = arr[0];
	sort(arr, arr + n * m, greater<int>());
	for (int i = 0; i < n * m; i++)
	{
		int temp = i / n + 1;
		if (arr[i] == a)
		{
			if (temp % 2 == 1)
			{
				cout << temp << ' ' << i % n + 1;
				break;
			}
			if (temp % 2 == 0)
			{
				cout << temp << ' ' << n - i % n;
			}
		}
	}
	
	cin.close();
	cout.close();
	
	return 0;
}
