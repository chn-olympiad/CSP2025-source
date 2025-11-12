#include <bits/stdc++.h>
using namespace std;
int n, k;
int a[500005], sum[500005], f[500005];
bool check(int l, int r)
{
	return (sum[l-1]^sum[r])==k;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w", stdout);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		sum[i] = sum[i-1]^a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		f[i] = f[i-1];
		if (a[i]==k)
			f[i]=f[i-1]+1;
		for (int j = 1; j <= i; j++)
		{
			if (check(j, i))
			{
				f[i] = max(f[i], f[j-1]+1);
			}
		}
	}
	cout << f[n];
	return 0;
}
