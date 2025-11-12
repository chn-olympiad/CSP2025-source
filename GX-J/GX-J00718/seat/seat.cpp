#include <iostream>
using namespace std;
int n,m,a[105];
int main()
{
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
	{
		cin >> a[i];
	}
	int r = a[1];
	sort(a + 1,a + n * m + 1);
	for(int i = n * m;i >= 1;i--)
	{
		if(a[i] == r)
		{
			break;
		}
		cnt++;
	}
	if((cnt / n) % 2 == 0)
	{
		cout << cnt % n << " " << cnt / n;
	}
	else
	{
		cout << n - cnt % n << " " << cnt / n;
	}
	return 0;
}
