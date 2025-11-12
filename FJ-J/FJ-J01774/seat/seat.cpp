#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n, m, t, a[N];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n * m;i++)
		cin >> a[i];
	t = a[1];
	sort(a + 1, a + n * m + 1);
	int k = n * m - (lower_bound(a + 1, a + n * m + 1, t) - a) + 1;
	int c = (k - 1) / n + 1;
	if(c & 1)
		cout << c << " " << k - (c - 1) * n << "\n";
	else
		cout << c << " " << n - k + (c - 1) * n + 1 << "\n";
	return 0;
}
