#include <bits/stdc++.h>

using namespace std;

int n;
int a[5010], maxn = -1;
int sum;
long long s[5010], ans;


int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		maxn = max(maxn, a[i]);
		sum += a[i];
	}
	if(n == 3)
	{
		if(sum > maxn * 2)
		{
			cout << 1 << '\n';
		}
		else
		{
			cout << 0 << '\n';
		}
	}
	else if(maxn == 1)
	{
		s[0] = 1;
		for(int i = 1; i <= n; i ++)
		{
			s[i] = s[i - 1] * i;
		}
		for(int i = 3; i <= n; i ++)
		{
			ans += s[n] / (s[n - i] * s[i]);
			ans %= 998244353;
		}
		cout << ans << '\n';
	}
	else cout << 1 << '\n';
	return 0;
}
