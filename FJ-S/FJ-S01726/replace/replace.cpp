#include <iostream>
#include <vector>
using namespace std;

int n, q;
pair<string, string> a[200005];

vector<int> kmp(string main, string pattern) {
	string s = pattern + "#" + main;
	int n = s.size();
	vector<int> pi(n);
	vector<int> res;
	for (int i = 1; i < n; i++) {
		int len = pi[i - 1];
		if (s[len] == s[i]) {
			pi[i] = len + 1;
		}
		if (pi[i] == pattern.size())
			res.push_back(i - pattern.size() * 2);
	}
	return res;
}

int main() {
  freopen("replace.in", "r", stdin);
  freopen("replace.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
  cin >> n >> q;
  for (int i = 1; i <= n; i++)
  	cin >> a[i].first >> a[i].second;
  	
  while (q--) {
  	string x, y;
  	cin >> x >> y;
  	int ans = 0;
  	for (int i = 1; i <= n; i++) {
  		auto v = kmp(x, a[i].first);
  		for (auto j : v) {
  			string tmp = x;
	  		if (y == tmp.replace(j, a[i].first.size(), a[i].second))
	  			ans++;
			}
		}
  	cout << ans << '\n';
	}
  return 0;
}


