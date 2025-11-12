#include<bits/stdc++.h>
using namespace std;
#define sns string::npos
const int N = 2e5 + 7;
string a[N], b[N];
void Cin_s(string &s) {
	char c;
	while (1) {
		scanf("%c", &c);
		if (c == 32 || c == 10) return;
		s += c;
	}
}
void Cin_i(int &n) {
	char c;
	n = 0;
	while (1) {
		scanf("%c", &c);
		if (c == 32 || c == 10) return;
		n = n * 10 + c - '0';
	}
}
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	Cin_i(n), Cin_i(q);
	for (int i = 1; i <= n; ++i) Cin_s(a[i]), Cin_s(b[i]);
	for (int i = 1; i <= q; ++i) {
		string x, y, u, v;
		int l, r, ans = 0;
		Cin_s(x), Cin_s(y);
		for (int j = 0; j < x.size(); ++j) {
			if (x[j] != y[j]) {
				l = j;
				break;
			}
		}
		for (int j = x.size() - 1; j >= 0; --j) {
			if (x[j] != y[j]) {
				r = j;
				break;
			}
		}
		for (int j = l; j <= r; ++j) u += x[j], v += y[j];
		for (int j = 1; j <= n; ++j) {
			if (a[j].find(u) != sns && b[j].find(v) != sns && x.find(a[j]) != sns && y.find(b[j]) != sns) {
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
