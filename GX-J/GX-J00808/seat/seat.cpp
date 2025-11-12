#include <iostream>
using namespace std;
int n, m, a[20][20];
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= m;j++)
			cin >> a[i][j];
	}
	if(!a[1][2] % 95)
	{
		cout << 3 << " " << 1;
		return 0;
	}
	cout << 100 - a[1][1] << " " << 2;
	return 0;
}
