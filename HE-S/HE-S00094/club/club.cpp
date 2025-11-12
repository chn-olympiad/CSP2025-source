#include <bits/stdc++.h>
using namespace std;

struct abc {
	long long a1;
	long long a2;
	long long a3;
};
abc a[100007];

int main () {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	long long t;
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
			long long m = max(a[i].a1, a[i].a2);
			m = max(m, a[i].a3);
			ans += m;
		}
		cout << ans << endl;
	}
	return 0;
}
