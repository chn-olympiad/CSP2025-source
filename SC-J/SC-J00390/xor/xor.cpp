#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair <int, int>
#define endl "\n"

const int N = 5E5 + 10;
int a[N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, k, maxx = -1, minn = 1e9;
	cin >> n >> k;
	
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
		minn = min(minn, a[i]);
	}
	
	if (k == 0 && maxx == 1 && minn == 1) {
		cout << n / 2 << endl;
	} else if (k <= 1 && minn == 0 && maxx == 1) {
		if (k == 1) {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 1) ++cnt;
			}
			cout << cnt << endl;
		} else {
			int cnt = 0;
			for (int i = 1; i <= n; ++i) {
				if (a[i] == 0) ++cnt;
			}
			cout << cnt;
		}
	} else {
		int ans = 0, o = a[1];
		for (int i = 2; i <= n; ++i) {
			if (o == k) {
				++ans;
				o = a[i];
			} else {
				o ^= a[i];
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
