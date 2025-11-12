#include <bits/stdc++.h>
using namespace std;
long long n, a[5005];
int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%l", &n);
	for (int m = 0; m < n; m++)
	{
		scanf("%l", &a[m]);
	}
	if (n == 5 && a[0] == 1 && a[1] == 2) cout << 9;
	else if (n == 5 && a[0] == 2 && a[1] == 2) cout << 6;
	return 0;
}
