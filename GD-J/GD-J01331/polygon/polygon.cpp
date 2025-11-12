#include <bits/stdc++.h> 
using namespace std;
int mod = 998244353;
int a[5005];
int b[5005];
int maxa(int n, int m)
{
	int maxn = 0;
	for (int i = n; i <= m; i++) maxn = max(maxn, a[i]);
	return maxn;
}
int suma(int n, int m)
{
	int sum = 0;
	for (int i = n; i <= m; i++) sum += a[i];
	return sum;
}
int maxb(int n, int m)
{
	int maxn = 0;
	for (int i = n; i <= m; i++) maxn = max(maxn, b[i]);
	return maxn;
}
int sumb(int n, int m)
{
	int sum = 0;
	for (int i = n; i <= m; i++) sum += b[i];
	return sum;
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int n, cnt = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	if (n == 3){
		int j = 1, k = 3;
		int maxn = maxa(j, k);
		int sum = suma(j, k);
		if (maxn * 2 < sum) cnt = (cnt + 1) % mod;
	}
	if (n > 3){
		for (int i = 3; i <= n; i++)
		{
			for (int s = 3; s <= i; i++)
			{
				do{
					int sum = sumb(1, i);
					int maxn = maxb(1, i);
					if (maxn * 2 <= sum) cnt = (cnt + 1) % mod;
				}
				while (next_permutation(b + 1, b + i + 1));
			}
		}
	}
	cout << cnt;
	return 0;
}
