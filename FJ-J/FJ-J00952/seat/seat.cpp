#include <bits/stdc++.h>
using namespace std;
int a[1005], n, m, R;
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;	
	for (int i = 1; i <= n * m; i++)
	{
		cin >> a[i];
	}
	R = a[1];
	sort(a + 1, a + n * m + 1, cmp);
	for (int i = 1; i <= n * m; i++)
	{
		//cout << a[i] << " ";
		if (a[i] == R)
		{
			R = i;
			break;
		}
	}
	//cout << "\n";
	int ans = R % (2 * n);
	if (ans == 0) ans = 2 * n; 
	int ans2 = (R - ans) / n;
	//cout << R << " " << ans << " " << ans2 << endl;
	if (ans <= n)
	{
		cout << ans2 + 1 << " " << ans;
	}
	else 
	{
		cout << ans2 + 2 << " " <<  n - (ans - n) + 1;
	}
	 
}
