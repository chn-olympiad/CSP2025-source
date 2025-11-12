#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int n, k, a[N];
bool f[N];
long long ans;
int get(int l, int r)
{
	return a[r] ^ a[l - 1];
}
void fun(int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		f[i] = true;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (i > 1)
		{
			a[i] = (a[i - 1] ^ a[i]);
		}
	}
	for (int l = 1; l <= n; l++)
	{
		for (int r = l; r <= n; r++)
		{
			int x = get(l, r);
			if (x == k && !f[l] && !f[r])
			{
				fun(l, r);
				ans++;
			}
		}
	}
	printf("%lld", ans);
	return 0;
}
