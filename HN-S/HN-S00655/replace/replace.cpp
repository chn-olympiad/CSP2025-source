#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, q;

void solve () {
	string s1, s2;
	cin >> s1 >> s2;
	
	s1 += ' ', s2 += ' ';
	
	bool f = false;
	
	for (int i = 1; i <= s1.size(); i++) {
		if (s1[i] == s2[i]) f = true; 
	}
	
	if (!f) cout << 0 << endl;
}

int main () {
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	
	cin >> n >> q;
	
	while (n--) solve();
	
	return 0;
} 
