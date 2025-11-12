#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	vector<pair<string, string>> rep(n);
	for (int i = 0; i < n; i++) cin >> rep[i].first >> rep[i].second;
	for (int i = 0; i < q; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			size_t idx = s1.find(rep[i].first);	// 疑似没学KMP的人的最后手段 
			if (idx == string::npos) continue;
			string s3 = s1.substr(0, idx) + rep[i].second + s1.substr(idx + rep[i].first.length(), s1.size() - (idx + rep[i].first.size()));
			if (s2 == s3) cnt++;
		}
		cout << cnt << endl;
	}
	return 0;
} 
