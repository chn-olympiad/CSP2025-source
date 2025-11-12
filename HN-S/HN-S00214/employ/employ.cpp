#include <fstream>

using namespace std;

const int kMaxN = 501;

ifstream cin("employ.in");
ofstream cout("employ.out");

int n, m, ans, c[kMaxN];
string s;
bool f[kMaxN];

void D(int x, int ct, int o) {
	if (ct >= m) {
		ans++;
		return;
	}
	if (x > n) {
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			f[i] = 1;
			if (o >= c[i]) {
				D(x + 1, ct, o + 1);
			} else {
				D(x + 1, ct + (s[x] - '0'), o + (s[x] == '0'));
			}
			f[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m >> s, s = ' ' + s;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	D(1, 0, 0);
	cout << ans << '\n';
  return 0;
}

