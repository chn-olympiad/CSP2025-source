#include <bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
#define x first
#define y second
#define V vector
using namespace std;

int main()
{
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	V<int> a(n * m);
	for(int& x : a) cin >> x;
	int t = a[0];
	sort(a.begin(), a.end(), greater<int>());
	for(int i = 0; ; ++i)
		if(a[i] == t)
		{
			int x, y;
			y = i/n + 1;
			x = (y&1 ? i%n : n-1-i%n) + 1;
//			cout << i << '\n';
			cout << y << ' ' << x << '\n';
			return 0;
		}

	return 0;
}
