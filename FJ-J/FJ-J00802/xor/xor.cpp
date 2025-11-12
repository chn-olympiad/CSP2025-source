#include <bits/stdc++.h>
using namespace std;
const int N = 4e6 + 10;

int sum[N], tr[N], f[N], a[N];
int n, k;

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++ )
		cin >> a[i], sum[i] = sum[i - 1] ^ a[i];
	memset(tr, -0x3f, sizeof(tr));
	f[0] = 0, tr[0] = 0;
	for(int i = 1; i <= n; i ++ )
	{
		f[i] = f[i - 1];
		f[i] = max(f[i], tr[sum[i] ^ k] + 1);
		tr[sum[i]] = max(tr[sum[i]], f[i]);
	}
	cout << f[n];
	return 0;
}
