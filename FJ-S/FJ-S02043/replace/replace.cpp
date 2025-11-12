#include<bits/stdc++.h>
using namespace std;

int n, q;
string s, t;  
map<pair<string, string>, int> m;

pair<string, string> solve(string x, string y) {
	int l, r, cnt = 0;
	pair<string, string> ret;
	for(int i = 0; i < x.size(); i++) {
		if(x[i] != y[i] && cnt == 0) l = i, cnt = 1;
		else if(x[i] != y[i] && cnt == 2) cnt = 1;
		else if(cnt == 1 && x[i] == y[i]) r = i - 1, cnt = 2;  
	}
	if(cnt == 1) r = x.size() - 1;
	for(int i = l; i <= r; i++) {
		ret.first += x[i];
		ret.second += y[i];
	}
	return ret;
}

int main() {
	
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s >> t;
		if(s != t) m[solve(s, t)]++;
	}
	for(int i = 1; i <= q; i++) {
		cin >> s >> t;
		if(s.size() != t.size()) {
			cout << 0 << "\n";
			continue;
		}
		cout << m[solve(s, t)] << "\n";
	} 
	
	return 0;
} 
