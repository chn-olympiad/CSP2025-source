#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

struct mm {
	int a, b, c;
	int gt() {
		int p[3] = {a, b, c};
		sort(p, p + 3);
		return p[2] - p[1];
	}
} m[MAXN];

int ca, cb, cc;

bool cmp(mm a, mm b) {
	return a.gt() < b.gt();
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	for (int o = 0; o < t; o++) {
		ca = 0;
		cb = 0;
		cc = 0;
		int n;
		cin >> n;
		int p = 0;
		for (int i = 1; i <= n; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			m[i].a = a;
			m[i].b = b;
			m[i].c = c;
			if (a >= b && a >= c) {
				p += a;
				ca++;
			}
			else if (b >= a && b >= c) {
				p += b;
				cb++;
			}
			else if (c >= a && c >= b) {
				p += c;
				cc++;
			}
		}
		int cm = max(max(ca, cb), cc);
		int k = cm - n / 2;
		if (k <= 0) {
			cout << p << endl;
			continue;
		}
		sort(m + 1, m + 1 + n, cmp);
		for (int i = 1; i <= k; i++) {
			p -= m[i].gt();
		}
		cout << p << endl;
	}
	return 0;
}

