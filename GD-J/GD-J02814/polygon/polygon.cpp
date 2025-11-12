#include <bits/stdc++.h>
using namespace std;
int n, a[5005];
int mod = 998244353;
int A(int a, int b)
{
	int sum = 1;
	while(b)
	{
		sum *= a;
		sum %= mod;
		a--;
		b--;
	}
	return sum;
}
int C(int a, int b)
{
	return A(a, b) / A(b, b);
}
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	for(int i = 3; i <= n; i++)
	{
		ans += C(n, i) % mod;
	}
	cout << ans;
	return 0;
}
