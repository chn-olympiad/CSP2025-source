#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmd(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;//n行m列 
	int a[105] = {};
	for (int i = 1;i <= n * m;i ++)
	{
		cin >> a[i];
	}
	int r = a[1];
	int t = m * n;
	int biao = 0;
	sort(a + 1, a + t + 1, cmd);//从大到小排序 
	for (int i = 1;i <= n * m;i ++)
	{
		if (a[i] == r)
		{
			biao = i;
			break;
		}
	}//寻找a排第几 
//	for (int i = 1;i <= n * m;i ++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl << biao << endl << biao % n;
	int b = biao / n;
	if (biao % n == 0)
		cout << biao / n << " " << m;//能整除就放在最后一个 
	else if ((b + 1) % 2 == 0)
		cout << b + 1 << " " << m - (biao % n - 1);//偶数列就从后向前看 
	else
		cout << b + 1 << " " << biao % n;//奇数列就从前向后看 
	return 0;
}//orz燃尽了 
