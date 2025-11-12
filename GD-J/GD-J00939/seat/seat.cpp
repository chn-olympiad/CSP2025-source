#include <bits/stdc++.h>

#define rep(i, j, k) for(int i = (j); i <= (k); ++i)
#define dwn(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

constexpr int N = 1e2 + 7;

int a[N], f[N][N];

int main() {
	freopen("seat.in", "r", stdin), freopen("seat.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, value, id;
	cin >> n >> m;
	rep(i, 1, n * m) cin >> a[i];
	value = a[1];
	sort(a + 1, a + 1 + n * m, greater<int>());
	rep(i, 1, n * m)
		if(a[i] == value) {
			id = i;
			break;
		}
	int c = (id - 1) / n + 1, r;
	if(c & 1) r = (id - 1) % n + 1;
	else r = n - (id - 1) % n;
	cout << c << ' ' << r << endl;
	return 0;
}
