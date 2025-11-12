#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	long long n, m;
	cin >> n >> m;
	vector<long long> a((n + 1) * (m + 1), LLONG_MIN);
	for (long long i = 1 ; i <= n * m ; i++) cin >> a[i];
	auto cmp = [](long long a, long long b)->bool {
		return a > b;
	};
	long long R = a[1], idx = -1;
	sort(a.begin() + 1, a.end(), cmp);
	for (long long i = 1 ; i <= n * m ; i++) {
		if (a[i] == R) {
			idx = i;
			break;
		}
	}
	if (idx % n == 0) {
		cout << idx / n << " ";
		if ((idx / n) % 2 == 1) cout << n;
		else cout << 1;
		return 0;
	}
	else {
		cout << idx / n + 1 << " ";
		if (((idx / n) + 1) % 2 == 1) {
			cout << idx % n;
		} else {
			cout << n - idx % n + 1;
		}
		return 0;
	}
	return 0;
} 
