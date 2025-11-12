#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("seat.in", "r", stdin);
	freopen("seat.out", "w", stdout);
	long long n, m, seat;
	cin >> n >> m;
	vector <long long> a(n * m);
	for(int i = 0; i < a.size(); ++i)	cin >> a[i];
	seat = a[0];
	sort(a.begin(), a.end(), greater<long long>());
	for(int i = 1; i <= n; ++i) {
		if(i % 2) {
			for(int j = 1; j <= m; ++j) {
				if(seat == a[0]) {
					cout << i << " " << j << endl;
					exit(0);
				}
				a.erase(a.begin(), a.begin() + 1);
			}
		}	else {
			for(int j = m; j >= 1; --j) {
				if(seat == a[0]) {
					cout << i << " " << j << endl;
					exit(0);
				}
				a.erase(a.begin(), a.begin() + 1);
			}
		}
	}
	return 0;
}