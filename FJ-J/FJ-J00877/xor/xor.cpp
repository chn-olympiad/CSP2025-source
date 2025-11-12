#include <bits/stdc++.h>
using namespace std;

int a[500001];

long long xor_(int l, int r)
{
	long long lum = a[l];
	for (int i = l + 1;i <= r;i++)
	{
		lum = lum ^ a[i];
	}
	return lum;
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.ans", "w", stdout);
	
	int n, k;
	cin >> n >> k;
	for (int i= 1;i <= n;i++) cin >> a[i];
	
	long long ans = 0;
	for (int i = 1;i <= n - 1;i++)
	{
		for(int j = i;j <= n;j++)
		{
			if (xor_(i, j) == k) ans++;
		}
	}
	cout << ans;
	return 0;
}
