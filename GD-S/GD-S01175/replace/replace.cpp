#include <iostream>
#include <string>
#include <map>

using namespace std;

using ull = unsigned long long;

const int N = 2e5 + 7;

string s1[N], s2[N];

map<string, int> mp; // s1 -> i

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
		// s1[i] = '#' + s1[i];
		// s2[i] = '#' + s2[i];
		mp.insert({s1[i], i});
	}

	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()) {
			cout << 0 << '\n';
			continue;
		}
		int len = t1.size();
		t1 = '#' + t1;
		t2 = '#' + t2;
		int cnt = 0;
		for (int l = 1; l <= len; l++) {
			for (int r = l; r <= len; r++) {
				string y = t1.substr(l, r-l+1);
				// cerr << "l = " << l << ", r = " << r << ", y = " << y << endl;
				for (int i = 1; i <= n; i++) {
					if (y == s1[i]) {
						string x = t1.substr(0, l);
						string z = t1.substr(r + 1, len-r);
						if (x + s2[i] + z == t2) {
							cnt++;
						}
					}
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}

// bf 10pts 17:29