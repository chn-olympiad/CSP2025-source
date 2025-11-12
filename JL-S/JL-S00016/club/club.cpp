#include <bits/stdc++.h>
#define FileInAndOut(x) do { \
	freopen(#x ".in", "r", stdin); \
	freopen(#x ".out", "w", stdout); \
} while(0);

using namespace std;

int main() {
	FileInAndOut(club)
	
	int T, ans = 0; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<int> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				int v; cin >> v;
				c.push_back(v);
			}
			ans += *max_element(c.begin(), c.end());
			c.clear();
		}
		cout << ans << endl;
		ans = 0;
	}
	
	return 0;
}
