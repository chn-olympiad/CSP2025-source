#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int a[MAXN];
bool b[MAXN];

int main()
{
	freopen("xor.in", "r", stdin); freopen("xor.out", "w", stdout);
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++ i)
		scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 1; i <= n; ++ i)
	{
		for (int j = i; j <= n; ++ j)
		{
			int sum = 0;
			for (int h = i; h <= j; ++ h)
			{
				if (b[h])
				{
					sum = -1;
					break;
				}
			}
			if (sum == -1)
				continue;
			for (int h = i; h <= j; ++ h)
			{
				sum = sum ^ a[h];
				b[h] = 1;
			}
			if (sum == k)
				++ cnt;
		}
	}
	printf("%d\n", cnt * 2);
	return 0;
}

