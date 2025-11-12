#include <bits/stdc++.h>
#include <cstring>
using namespace std;

string become (string s, string t) {
	bool flag = false;
	int m = 0;
	int a = sizeof(t);
	int b = sizeof(s);
	for (int i = 0; i <= b - a; i++) {
		for (int j = 0; j < a; j++) {
			if(s[i+j] == t[j]) {
				m = j;
				flag = true;
			} else {
				flag = false;
			}
		}
		if (flag) {
			for (int j = m; j < a; j++) s[i+j] = t[j];
			break;
		}
	}
	return s;
}

int main () {
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	int n,q;
	cin >> n >> q;
	string s[n][2];
	string t[q][2];
	int m[q] = {0};
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> s[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> t[i][j];
		}
	}
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < n; j++) {
			string x = t[i][0];
			x = become(x,s[j][1]);
			if (x == t[i][1] || (t[i][0] == s[j][0] && s[j][1] == t[j][1])) {
				m[i]++;
			}
		}
	}

	for (int i = 0; i < q; i++) {
		cout << m[i] << endl;
	}
	return 0;
}
