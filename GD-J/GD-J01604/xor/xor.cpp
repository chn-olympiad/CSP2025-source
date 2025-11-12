#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5e5 + 5, MAXA = 1 << 20 + 5;
int n, k, last = 1, ans, l[MAXA], a[MAXN], pre[MAXN];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	memset(l, 0x3f, sizeof(l));
	for (int i = 1, t; i <= n; i++)
	{
		cin >> a[i];
		pre[i] = pre[i - 1] ^ a[i];
		int lj = l[pre[i] ^ k] + 1;
		l[pre[i]] = i;
		if (pre[i] == k && last == 1 || last <= lj && lj <= i)
		{
			last = i + 1;
			ans++;
		}
	}
	cout << ans;
	return 0;
}
