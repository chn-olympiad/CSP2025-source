#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n, m, a[N], f[N];
unordered_map<int, int> mm;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] ^= a[i-1];
	}
	for(int i = 1; i <= n; i++)
	{
		f[i] = f[i-1];
		int p = a[i]^m;
		int pp = mm[p];
		if(pp == 0)
		{
			if(p == 0)
				f[i] = max(f[i], 1);
		}
		else
			f[i] = max(f[i], f[pp]+1);
		mm[a[i]] = i;
	}
	printf("%d", f[n]);
	return 0;
}
