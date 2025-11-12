#include <bits/stdc++.h>
using namespace std;

pair<string, string> a[200003];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; ++i)
		cin >> a[i].first >> a[i].second;
	for(string s, t; q--; cout.put('\n')) {
		cin >> s >> t;
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			string r = s;
			size_t k = r.find(a[i].first);
			if(k != string::npos)
				r = r.substr(0, k) + a[i].second + r.substr(k+a[i].first.size());
			if(r == t)
				++ans;
		}
		cout << ans;
	}
	cout.flush(); return 0;
}
