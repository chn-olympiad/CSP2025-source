#include<bits/stdc++.h>
#define ll long long
#define str string
#define db double
using namespace std;
constexpr ll MAXN = 105;
ll n, m, fnd, a[MAXN];
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (ll i = 1; i <= n * m; ++i) cin >> a[i];
	fnd = a[1], sort(a + 1, a + n * m + 1, greater<ll>());
	for (ll i = 1; i <= n * m; ++i)
		if (a[i] == fnd) fnd = i;
	ll lie = (fnd - 1) / n + 1, hang = (fnd - 1) % n + 1;
	if (!(lie & 1))
		hang = (n + 1) - hang;
	cout << lie << ' ' << hang << '\n';
	return 0;
}