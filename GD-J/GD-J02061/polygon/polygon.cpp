#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5, mod = 998244353;
int a[N], n, cnt; 

int count(int x, int n)
{
	int t1 = 1, t2 = 1;
	for (int i = 1; i <= x; i++) t1 = t1 * i % mod;
	for (int i = n; i >= n - x + 1; i--) t2 = t2 * i % mod;
	return t2 / t1; 
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 3)
	{
		if (a[1] + a[2] > a[3] || a[2] + a[3] > a[1] || a[1] + a[3] > a[2]) cout << 1;
		else cout << 0;
	}
	else
	{
		for (int i = 3; i <= n; i++) cnt = (cnt + count(i, n)) % mod;
		cout << cnt;
	}
	return 0; 
}
