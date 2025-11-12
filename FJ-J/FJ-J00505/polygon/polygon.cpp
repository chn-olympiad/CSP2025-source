#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 5005;
const int mod = 998244353;

int n, a[N], s[N];
int f[N], c[N][N], ans;

void prepare()
{
	c[1][1] = 1;
	for(int i = 2; i <= 5000; i++)
	{
		c[i][i] = 1, c[i][1] = i;
		for(int j = 2; j < i; j++)
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
	}
	return;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n; int maxn = 0; prepare();
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn = max(a[i], maxn);
	}
	if(maxn == 1)
	{
		for(int i = 3; i <= n; i++)
		{
			ans = (ans + c[n][i]) % mod;
			cout << c[n][i] << endl;
		}
		cout << ans << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	if(n == 3)
	{
		if(a[1] + a[2] > a[3])
			ans = 1;
		cout << ans << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	for(int i = 3; i <= n; i++)
		for(int j = 2; j <= i; j++)
			for(int k = 1; j + k <= i; k++)
				if(s[j + k - 1] - s[k - 1] > a[i])
				{
					ans = (ans + c[i - k][j]) % mod;
					f[i] = (f[i] + c[i - k][j]) % mod;
					break;
				}
	cout << ans << endl;
	return 0;
}
