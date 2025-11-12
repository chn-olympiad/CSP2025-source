#include<bits/stdc++.h>
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int R, k;
	int a[10000];
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + 1 + n*m, cmp);
	for (int i = 1; i <= n * m; i++)
		if(a[i] == R)
			k = i;
	if((k - 1) / n % 2 == 0)
		printf("%d %d\n", (k - 1) / n + 1, (k - 1) % n + 1);
	else
		printf("%d %d\n", (k - 1) / n + 1, n - k % n + 1);
	return 0;
}
