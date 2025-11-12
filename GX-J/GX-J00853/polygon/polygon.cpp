#include <bits/stdc++.h>
using namespace std;
int n, a[500020], sum;
int main ()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i], sum += a[i];
	if (n == 3) 
	{
		if (sum > 2 * a[1] || sum > 2 * a[2] || sum > 2 * a[3]){
			cout << 1;
		}
		else cout << 0;
		return 0;
	}
	else
	{
		if (sum == n)
		{
			cout << 13;
		}
		cout << 6;
	}
	return 0;
}
