#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int n, k, a[N], ans, tmp = 0;
int main()
{
	freopen("xor.in", "r", stdin); 
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		if (a[i] == k)
		{
			ans++;
			cout << i << endl;
			tmp = 0;
		}
		else
		{ 
			tmp ^= a[i];
			if (tmp == k)
			{
				tmp = 0;
				ans++;
				cout << i << endl;
			}
		}
	}
	printf("%d", ans);
	return 0;
}
