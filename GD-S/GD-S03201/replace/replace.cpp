#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
string s1[N], s2[N];
int cnt;

int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);

	ios::sync_with_stdio(false);

	cin >> n >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	
	while (q--) {
		string t1, t2;
		cin >> t1 >> t2;
		
		for (int i = 0; i < t1.size(); i++) {
			for (int j = i+1; j < t1.size(); j++) {
				string tmp = t1.substr(i, j-i+1);
				string T1 = t1;
				for (int FIND = 1; FIND <= n; FIND++) {
					if (tmp == s1[FIND]) {
						t1.replace(i, j-i+1, s2[FIND]);
						
						if (t1 == t2)
							cnt++;
					}
				}
				t1 = T1;
			}
		}
		
		cout << cnt << "\n";
		cnt = 0;
	}
	return 0;
}

