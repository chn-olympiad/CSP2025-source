#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 100;
int n, k;
int a[N];
int sum;
bool pA = true, pB = true;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	if (k != 0) pA = false;
	if (k > 1) pB = false;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] > 1 && pB) pB = false;
		if (a[i] != 1 && pA) pA = false;
	}
	if (pA)
	{
		printf("%d", n / 2);
		return 0;
	}
	if (pB)
	{
		int sum1 = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] != a[i + 1])
			{
				sum++;
				i++;
			}
		}
		for (int i = n; i > 1; i--)
		{
			if (a[i] != a[i - 1])
			{
				sum1++;
				i--; 
			}
		}
		printf("%d", max(sum, sum1));
		return 0;
	}
	int tmp;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == k)
		{
			sum++;
			continue;
		}
		tmp = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			tmp ^= a[j];
			if (tmp == k)
			{
				sum++;
				i = j;
				break;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
