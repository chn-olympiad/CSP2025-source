#include <bits/stdc++.h>
typedef long long lng;
using namespace std;
const lng man = 2e5 + 5;
int a[105];
int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n * m; ++i)
		cin >> a[i];
	int sc = a[0], pos = 1;;
	sort(a, a + n * m, greater<int>{});
	for(; pos < n * m; pos++)
		if(a[pos] == sc) break;
	int c = pos / n, r = pos % n;
	if(c & 1) r = n - r - 1;
	cout << c + 1 << ' ' << r + 1 << '\n';
	return 0;
}