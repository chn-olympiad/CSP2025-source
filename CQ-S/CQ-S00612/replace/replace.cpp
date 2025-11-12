#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m;
string s1[N], s2[N];
//struct tire {
//	vector <int> tree[N][26];
//	void add(string s) {
//		for(int i = 1; i <= n; i++) {
//			
//		}
//	}
//};
vector <int> find(string &a, string &b) {
	int del = 0;
	vector <int> ret;
	while(a.size()) {
		int x = a.find(b);
		if(x > a.size()) break;
		ret.push_back(x + del);
		del += x + b.size();
		a.erase(a.begin(), a.begin() + x + b.size());
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> s1[i] >> s2[i];
	}
	for(int i = 0; i < m; i++) {
		string t1, t2;
		cin >> t1 >> t2;
		for(int i = 0; i < n; i++) {
			int ans = 0;
			vector <int> g1 = find(s1[i], t1);
			vector <int> g2 = find(s2[i], t2);
			for(int i = 0; i < g1.size(); i++) {
				for(int j = 0; j < g2.size(); j++) {
					if(g1[i] == g2[i]) {
						ans ++;
					}
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
