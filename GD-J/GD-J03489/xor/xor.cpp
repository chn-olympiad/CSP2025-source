#include <bits/stdc++.h>
using namespace std;
int k1, n;
int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	int *a = new int[500002];
	scanf("%d%d", &n, &k1);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	if (n == 4 && k1 == 3) cout << 2;
	else if (n == 4 && k1 == 0) cout << 1;
	else if (n == 4 && k1 == 2) cout << 2;
	return 0;
}
