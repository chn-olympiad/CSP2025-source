#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5;
const int maxv = 2e6;


int n, k;
int a[maxn + 5];
int sum[maxn + 5];
int q[maxv + 5];
int f[maxn + 5];
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	 
	cin >> n >> k;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i-1] ^ a[i];
	memset(q, 0xff, sizeof(q));
	q[0] = 0;
	for(int i = 1; i <= n; ++i)
	{
		int lst = q[sum[i] ^ k];
		q[sum[i]] = i;
		f[i] = f[i-1];
		if(~lst)
			f[i] = max(f[i], f[lst] + 1);
	}
	cout << f[n] << endl;
	return 0;
}