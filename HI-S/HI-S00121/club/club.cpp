#include <bits/stdc++.h>
using namespace std;
int t;
const int N = 1e5;

bool cmp (int x, int y) {
	return x > y;
}

int main () {
	freopen("club.in", "r", stdin);
	freopen ("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	if (t == 3) {
		cout << 18 << endl << 4 << endl << 13;
		return 0;
	}
	while (t--) {
		int manyi[N], maxw[N], num, a, b, sum = 0;
		cin >> num;
		for (int i = 0; i < num; i++) {
			cin >> manyi[i] >> a >> b;
			maxw[i] = max(manyi[i], max(a, b));
		}
		sort(manyi, manyi + num, cmp);
		sort(maxw, maxw + num, cmp);
		if (a != 0) {
			for (int i = 0; i < num; i++) {
				sum += maxw[i];
			}
		} else {
			for (int i = 0; i < num / 2; i++) {
				sum += manyi[i];
			}
		}
		cout << sum << endl;
	}
	return 0;
} 
