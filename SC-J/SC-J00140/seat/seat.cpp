#include<bits/stdc++.h>
#define ll long long
#define _for(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
int n, m, a[105], r, t;
int main()
{
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	cin >> n >> m;
	_for(i, 1, n * m) cin >> a[i];
	r = a[1];
	sort(a + 1, a + n * m + 1, greater<int>());
	_for(i, 1, n * m) if(a[i] == r) t = i;
	int a = t % n ? t / n + 1 : t / n, b = t % n ? t % n : n;
	cout << a << ' ' << (a % 2 ? b : n - b + 1);
	return 0;
}