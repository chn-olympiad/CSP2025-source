#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;

const int N = 2e5 + 5;
int n, q;
string s[N][3];

int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s[i][1] >> s[i][2];
	}
	while (q--) {
		int cnt = 0;
		string a, b;
		cin >> a >> b;
		for (int i = 1; i <= n; i++) {
			if (a.find(s[i][1]) != string::npos && b.find(s[i][2]) != string::npos) {
				int pos = a.find(s[i][1]);
				string x = a.substr(0, pos), y = a.substr(pos + s[i][1].size(), a.size() - pos - s[i][1].size());
				if ((x + s[i][1] + y == a && x + s[i][2] + y == b) || (a == s[i][1] && b == s[i][2])) cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
//Help me accept!!!!!
