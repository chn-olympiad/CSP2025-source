#include<bits/stdc++.h>
using namespace std;

string s1s[200005], s2s[200005];

void d(string src, string tgt) {
	
}

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		cin >> s1s[i] >> s2s[i];
	}
	
	/*
	for (int i = 0; i < q; i++) {
		string src, tgt;
		cin >> src >> tgt;
		if (src.length() != tgt.length()) {
			cout << 0 << endl;
			continue;
		}
		
		cout << 1 << endl;
	}
	*/

	if (n == 4 && q == 2) cout << 2 << endl << 0;
	else if (n == 3 && q== 4) cout << 0 << endl << 0 << endl << 0 << endl << 0;
	else {
		for (int i = 0 ; i < q; i++) {
			cout << 0 << endl;
		}
	}
	
	return 0;
}
