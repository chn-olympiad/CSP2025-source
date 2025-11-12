#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
using LL = long long;

const int kMaxN = 1e5 + 1;

ifstream cin("club.in");
ofstream cout("club.out");

LL t, n, s, a[kMaxN][3];
vector<LL> v[3];

int main() {
	for (cin >> t; t; t--) {
		cin >> n;
		v[0].clear(), v[1].clear(), v[2].clear(), s = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
			}
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]) {
				s += a[i][0];
				v[0].push_back(max(a[i][1], a[i][2]) - a[i][0]);
			} else if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]) {
				s += a[i][1];
				v[1].push_back(max(a[i][0], a[i][2]) - a[i][1]);
			} else {
				s += a[i][2];
				v[2].push_back(max(a[i][0], a[i][1]) - a[i][2]);
			}
		}
		int o = n / 2;
		for (int i = 0; i < 3; i++) {
			sort(v[i].begin(), v[i].end(), greater<LL>());
			if (v[i].size() > o) {
				for (int j = 0; j < v[i].size() - o; j++) {
					s += v[i][j];
				}
			}
		}
		cout << s << '\n';
	}
  return 0;
}

