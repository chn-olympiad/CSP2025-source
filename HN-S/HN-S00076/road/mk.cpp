#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(x) (x).begin(), (x).end()
bool be;
mt19937 rd(time(0));
bool en;
int main()
{
	freopen("road.in", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n = 1e4, m = 1e6, k = 10;
	cout << n << ' ' << m << ' ' << k << '\n';
	for (int i = 1; i <= m; ++i) {
		int u = rd() % n + 1, v = rd() % n + 1, w = rd() % 1000000000 + 1;
		cout << u << ' ' << v << ' ' << w << '\n';
	}
	for (int i = 0; i < k; ++i) {
		cout << rd() % 1000000000 + 1 << ' ';
		for (int j = 1; j <= n; ++j) {
			cout << rd() % 1000000000 + 1 << ' ';
		}
		cout << '\n';
	}
	return 0;
}