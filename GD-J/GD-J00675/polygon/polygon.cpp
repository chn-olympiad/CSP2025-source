#include <bits/stdc++.h>
using namespace std;
typedef long long ll;	
ll n;
ll a[5001], s[5001];
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	set<string> st;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s[i] = s[i-1] + a[i];
	}
	int ans = 0;
	for (int i = 3; i <= n; i++) {
		int l = 0, r = 0;
		while (l <= r) {
			int he = s[i] - (s[r] - s[l-1]);
			if (he > 2 * a[i]) {
				string s;
				for (int j = 1; j <= i; j++) {
					if (!(j >= l && j <= r)) {
						s += j;
					}
				}
				st.insert(s);
			}
			if (r + 1 <= i - 3) r++;
			else if (l + 1 <= i - 1) {
				l++;
				r = l;
			} else {
				break;
			}
		}
	}
	cout << st.size();
	return 0;
}
