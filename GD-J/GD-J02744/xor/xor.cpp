#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
int n, k, cnt;
int a[N];

signed main()
{
	freopen ("xor.in", "r", stdin);
	freopen ("xor.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int l = 1, r = 1;
	while (l <= n)
	{
		bool f = 1;
		if (r == n)
		{
			f = 0;
		}
		int sum = 0;
		for (int i = l; i <= r; i++)
		{
			sum ^= a[i];
		}
		if (sum == k)
		{
			l = r + 1;
			r = l;
			cnt++;
			continue;
		}
		if (f)
		{
			r++;
		} 
		else
		{
			l++;
			r = l;
		}
	}
	cout << cnt << '\n';
	
	return 0;
}

