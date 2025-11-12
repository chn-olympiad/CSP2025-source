#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
    int n, m, b;
    cin >> n >> m;
    int a[n * m];
    for (int i = 0;i <= n * m; i++)
	{
		cin >> a[i];
    } 
    b = a[0];
    sort(a + 1, a + n * m + 1);
    for (int i = 0; i <= n * m; i++)
	{
		if (a[i] == b)
		{
			cout << (i - (i % 4)) / 4 + 1 << " " << i % 4;
		}
    } 
	return 0;
}
