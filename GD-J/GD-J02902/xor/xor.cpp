#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 1;
map<int, int> maxn;
int n, k, a[N], b[N], f[N], F[N];
signed main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
	}
	F[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i - 1];
		int y = b[i] ^ k;
		if(F[y])
		{
			f[i] = max(f[i], maxn[y] + 1);
		}
		maxn[b[i]] = max(maxn[b[i]], f[i]);
		F[b[i]] = 1;
	}
	cout << f[n];
}
