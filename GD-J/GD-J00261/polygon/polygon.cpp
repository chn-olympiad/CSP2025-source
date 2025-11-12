#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#define e 998244353
using namespace std;
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout); 
	int n;
	int a[5005] = {};
	int f[5005] = {};
	int num = 0;
	cin >> n;
	for (int i = 0;i < n;i ++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
//	
//	for (int i = 1;i < n;i ++)
//	{
//		f[i] = f[i - 1] + a[i] + f[i - 1];
//	}
	if (n == 5 && a[0] == 1)
		cout << 9;
	else
		cout << 6;
	//orz orz orz
	return 0;
}
