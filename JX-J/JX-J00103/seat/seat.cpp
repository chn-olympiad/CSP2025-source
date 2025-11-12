#include <bits/stdc++.h>
#define frein(x) freopen(x, "r", stdin);
#define freot(x) freopen(x, "w", stdout);
using namespace std;
using ll = long long;
pair<int, int> a[505];
int n, m;
int main() {
	frein("seat.in");
	freot("seat.out");
	cin.tie(0)->ios::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 1; i <= n * m; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n * m, greater<pair<int, int> >());
	int nowid = 1;
	for (int i = 1; i <= n * m; ++i) {
		if (a[i].second == 1) {
			nowid = i;
			break;
		}
	}
	int hang = 0, lie = 0;
	lie = (nowid + n - 1) / n;
	hang = (nowid - 1) % n + 1;
	if (lie % 2 == 0) {
		hang = n - hang + 1;
	}
	cout << lie << ' ' << hang;
	
	return 0;
}
