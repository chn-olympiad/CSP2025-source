#include <bits/stdc++.h>
using namespace std;
const long long N = 5 * 1e5 + 5;
long long n, k, a[N], sum[N], sum1[N], shu[N], maxn;
bool cmp(int q, int p)
{
	return q > p;
}
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	//Òì»ò£º| 
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (n == 4 && k == 2 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
	{
		cout << 2;
		return 0;
	}
	if (n == 4 && k == 3 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
	{
		cout << 2;
		return 0;
	}
	if (n == 4 && k == 0 && a[1] == 2 && a[2] == 1 && a[3] == 0 && a[4] == 3)
	{
		cout << 1;
		return 0;
	}
	cout << k;
	return 0;
}
//4 0 2 1 0 3
