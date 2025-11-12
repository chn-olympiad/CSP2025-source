#include <bits/stdc++.h>
using namespace std;

// source - source string
// targ - which one in source should be replaced
// replace - replace with what
string _replace(string source, string targ, string replace) {
	string result = source;
	auto findPosition = source.find(targ);
	
	if (findPosition != std::string::npos) {
		result.replace(findPosition, replace.size(), replace);
	}
	return result;
}

struct u {
	string first;
	string second;
	
	u() = default;
	u(const string &f, const string &s) {}
};

vector<u> stringPairs;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	stringPairs.resize(n);
	for (int i = 0; i < n; i++) {
		string a, b; cin >> a >> b;
		stringPairs[i] = u(a, b);
	}
	
	long long ans = 0;
	
	for (int i = 0; i < q; i++) {
		ans = 0;
		string t1, t2; cin >> t1 >> t2;
		for (auto i : stringPairs) {
			if (_replace(t1, i.first, i.second) == t2) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	
	return 0;
}
