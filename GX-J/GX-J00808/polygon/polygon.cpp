#include <iostream>
using namespace std;
int main()
{
	int n, a[5010];
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	cout << (4 - a[n] / 5) * 3;
	return 0;
}
