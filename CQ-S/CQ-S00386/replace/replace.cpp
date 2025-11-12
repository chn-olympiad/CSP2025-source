#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e5 + 5;

int n, m;
pair <string, string> S[N];

int bfs (string s1, string s2) {
	int l = s1.size ();
	queue <string> Q; Q.push (s1);
	int ans = 0;
	while (Q.size ()) {
		auto t = Q.front (); Q.pop ();
//		cerr << t << ' ';
		if (t == s2) ans ++ ;
		if (t != s1) continue;
		for (int i = 0; i < l; i ++ ) for (int j = 1; j <= n; j ++ ) if (t.substr (i, S[j].first.size ()) == S[j].first) Q.push (t.substr (0, i) + S[j].second + t.substr (i + S[j].first.size (), n - i + S[j].first.size ()));
	}
	
	return ans;
}

void solve () {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ ) cin >> S[i].first >> S[i].second;
	while (m -- ) {
		string s1, s2; cin >> s1 >> s2;
		cout << bfs (s1, s2) << '\n';
	}
}

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	cin.tie (nullptr) -> sync_with_stdio (false);

	int T = 1;
//	cin >> T;
	while (T -- ) solve ();
	return 0;
}

