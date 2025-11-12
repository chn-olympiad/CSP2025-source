#include <iostream>
#include <string>
using namespace std;

int n, m;
string exam;
int c[505];

int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> exam;
	int num = 0;
	for (int i = 1; i <= n; i++) 
	{
		cin >> c[i];
		if (c[i] == 0)
		{
			num++;
		}
	}
//	cout << num << endl;
//	num = 0;
	
	if (n - num < m)
	{
		cout << 0;
		return 0;
	}
	
	long long ans = 1;
	for (int i = n; i >= 1 + num; i--)
	{
		ans = ans * i;
		ans = ans % 998244353;
	}
	cout << ans;
	return 0;
}

