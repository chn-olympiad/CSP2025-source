#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, q;
string s1[N], s2[N];
string t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++ ) cin >> s1[i] >> s2[i];
	while (q -- ) {
		cin >> t1 >> t2;
		for (int i = 0; i < t1.size(); i ++ ) {
			string str;
			for (int j = i; j < t1.size(); i ++ ) {
				str += t1[i];
				for (int k = 1; k <= n; k ++ ) {
					if (str == s1[k]) {
						string t1l;
						for (int l = 0; l < i; l ++ ) t1l += t1[l];
						t1l += s2[k];
						for (int l = j + 1; l < t1.size(); l ++ ) t1l += t1[l];
						t1 = t1l;
					}
				}
			}
		}
		cout << q << endl;
	}
	return 0;
} 
