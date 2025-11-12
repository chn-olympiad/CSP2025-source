#include<bits/stdc++.h>
using namespace std;
int n, m, r, a[101], s;
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n * m; i++)
		cin >> a[i];
	r = a[1], sort(a + 1, a + n * m + 1);
	for(int i = 1; i <= n * m; i++)
		if(a[i] == r)
		{
			s = n * m - i + 1;
			break;
		}
	cout << (s - 1) / n + 1 << ' ';
	if(((s - 1) / n + 1) % 2)
		cout << (s - 1) % n + 1;
	else
		cout << n - (s - 1) % n;
	return 0;
}
