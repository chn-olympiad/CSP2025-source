#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
int n, q;
int st,en, ans;
string s1[N], s2[N];
string t1, t2;
string p1, p2;
map <string, string> s;
map <string, bool> b;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> s1[i] >> s2[i];
		s[s1[i]] = s2[i];
		b[s1[i]] = 1;
	}
	for (int i = 1; i <= q; ++i) {
		cin >> t1 >> t2;
		if(t1.size() != t2.size()) {
			cout << "0\n";
			continue;
		}
		int len = t1.size();
		for(int j = 0; j < len; ++j) {
			if(t1[j] != t2[j]){
				st = j;
				break;
			}
		}
		for(int j = len - 1; j >= 0; ++j) {
			if(t2[j] != t1[j]){
				en = j;
				break;
			}
		}
		for(int j = 0; j <= st; ++j) {
			p1 = p2 = "";
			for(int k = j; k < len; ++k) {
				p1 += t1[k], p2 += t2[k];
				if(k >= en) {
					if(b[p1] == 0) continue;
					else if(s[p1] == p2) ans++;
				}
			}
		}
		cout << ans <<"\n";
	}
	return 0;
}

