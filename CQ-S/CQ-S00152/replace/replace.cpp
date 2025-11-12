#include<bits/stdc++.h>
#define ll long long
#define fast_running ios::sync_with_stdio(false), cin.tie(0)
using namespace std;
const int N = 2e5 + 5;
int n, q, ans;
struct music{
	string a, b;
}g[N];
void dfs(string s, string xl) {
	if (s == xl) {
		++ans;
		return;
	}
	for (int i = 1; i <= n; i++) {
		int at = s.find(g[i].a);
		if (0 <= at && at <= s.size()) {
			string f = s;
			for (int j = at; j < at + g[i].a.size(); j++) {
				s[j] = g[i].b[j];
			}
			dfs(s, xl);
			s = f;
		}
	}
	return;
}
int main() {
	fast_running;
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> g[i].a >> g[i].b;
	while(q--) {
		ans = 0;
		string x, y;
		cin >> x >> y;
		dfs(x, y);
		cout << ans << '\n';
	}
	return 0;
}

