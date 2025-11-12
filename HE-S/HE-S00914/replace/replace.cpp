#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

struct node {
	string a, b;
};

const int MAXN = 2e5 + 5;
node s[MAXN];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i].a >> s[i].b;
	}
		while (q--) {
			int ans = 0;
			string a, b;
			cin >> a >> b;
			for (int i = 1; i <= n; i++) {
				ULL t = a.find(s[i].a);
				if (t == string::npos) continue;
				string tmp = a;
				tmp.replace(t, s[i].b.size(), s[i].b);
				if (tmp == b) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	return 0;
}
