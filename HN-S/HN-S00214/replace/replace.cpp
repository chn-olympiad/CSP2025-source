#include <fstream>
#include <map>

using namespace std;
using LL = long long;

const int kMaxN = 3e6 + 1;
const LL kP = 13331, kMod = 114917813;

ifstream cin("replace.in");
ofstream cout("replace.out");

int n, q, ct;
LL p[kMaxN], h[kMaxN];
string now, to;
struct P {
	string a, b;
	LL ha, hb;
} r[kMaxN];
map<string, LL> mp;

void I() {
	p[0] = 1; 
	for (int i = 1; i < kMaxN; i++) {
		p[i] = p[i - 1] * kP % kMod;
	}
}

LL H(int l, int r) {
	if (r < l) {
		return 0; 
	}
	return ((h[r] - h[l - 1] * p[r - l + 1] % kMod) % kMod + kMod) % kMod;
}

int main() {
	I();
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> r[i].a >> r[i].b;
		for (int j = 0; j < r[i].a.size(); j++) {
			r[i].ha = (r[i].ha * kP % kMod + r[i].a[j]) % kMod;
			r[i].hb = (r[i].hb * kP % kMod + r[i].b[j]) % kMod;
		}
//		cout << r[i].ha << ' ' << r[i].hb << '\n';
	}
	for (string a, b; q; q--) {
		cin >> a >> b;
		if (a.size() != b.size()) {
			cout << 0 << '\n';
			continue;
		}
		int cnt = 0;
		LL hb = 0;
		for (int i = 0; i < a.size(); i++) {
			h[i + 1] = (h[i] * kP % kMod + a[i]) % kMod;
//			cout << h[i + 1] << ' ';
			hb = (hb * kP % kMod + b[i]) % kMod;
		}
//		cout << '\n';
//		cout << hb << '\n';
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j + r[i].a.size() - 1 < a.size(); j++) {
//				cout << j << ' ' << r[i].a << '\n';
				LL o1 = h[j], o2 = H(j + r[i].a.size() + 1, a.size());
//				cout << o2 << '\n';
				if (H(j + 1, j + r[i].a.size()) == r[i].ha) {
//					cout << o1 << ' ' << r[i].hb << ' ' << o2 << '\n';
					if ((o1 * p[a.size() - j] + r[i].hb * p[a.size() - j - r[i].a.size()] % kMod + o2 % kMod) % kMod == hb) {
						cnt++;
//						cout << j << '\n';
						break;
					}
				}
			}
		}
		cout << cnt << '\n';
	}
  return 0;
}
// ShangShanRuoShui
// RenJieDiLing 
