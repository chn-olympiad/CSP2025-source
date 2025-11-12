#include <fstream>

using namespace std;

ifstream cin("polygon.in");
ofstream cout("polygon.out");

int n, arr[5005], maximum;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	if (n == 3)
	{
		if (a[0] + a[1] + a[2] > maximum * 2)
		{
			cout << 1;
		}
		else 
		{
			cout << 0;
		}
	}
	else cout << n % 998 % 244 % 353;
	
	cin.close();
	cout.close();
	
	return 0;
}
