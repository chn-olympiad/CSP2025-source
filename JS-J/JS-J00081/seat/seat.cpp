#include<bits/stdc++.h>
using namespace std;
int n, m, a[101], pm;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++) cin >> a[i];
	int r = a[1];
	sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++)
	{
		if(a[i] == r)
		{
			pm = n * m - i + 1;
			break;
		}
	}
	if(pm % (2 * n) > n) cout << pm / (2 * n) + 2 << " " << 2 * n - (pm % (2 * n)) + 1;
	else cout << pm / (2 * n) + 1 << " " << pm % (2 * n);
	return 0;
}
