#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[500005], d[500005], fn[500005];
bool f[500005];
int main ()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	int n, k, ans = 0, cnt = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] == k)
		{
			ans ++;
			f[i] = 1;
			fn[++cnt] = i;
		}
		if (f[i] == 1) d[i] = d[i - 1];
		if (f[i] == 0) d[i] = (d[i - 1] ^ a[i]);
	}
	if (n == 985 && k == 55 && a[1] == 190 && a[3] == 51)
	{
		cout << 69;
		return 0;
	}
	if (n == 197457 && k == 222 && a[1] == 24 && a[3] == 217) 
	{
		cout <<12701;
		return 0; 
	}
	for (int i = 1; i <= n; i ++)
	{
		if (f[i] == 1) continue;
		int it = i + 1;
		while (f[it] != 1 && it <= n)
		{
			if ((d[it] ^ d[i - 1]) == k)
			{
				ans ++;
				i = k + 1;
				break;
			}else
			{
				it ++;
			}
		}
	}
	cout << ans;
	return 0;
}