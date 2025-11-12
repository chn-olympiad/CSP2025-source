#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n, m, ans = 0;
char s[505];
int c[505];
int main()
{
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> c[i];
	}
	cout << ans % mod << endl;
}
