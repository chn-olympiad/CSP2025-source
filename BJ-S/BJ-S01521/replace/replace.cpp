#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 2e5 + 5;
string s1[N], s2[N];
string t1, t2;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> s1[i] >> s2[i];
	}
	while(q--) {
		cin >> t1 >> t2;
		int diff = 0;
		for(int i = 0; i < t1.size(); i++) {
			if(t1[i] != t2[i]) diff++;
		}
		int res = 0;
		for(int i = 1; i <= n; i++) {
			int remdif = diff;
			int p = 0;
			for(int j = 0; j < t1.size(); j++) {
				if(s1[i][p] == t1[j]) {
					if(s2[i][p] == t2[j]) p++, remdif--;
				} else {
					p = 0;
					remdif = diff;
				}
				if(remdif == 0) res++;
			}
			lped: ;
		}
		printf("%d\n", res);
	}
	return 0;
}
