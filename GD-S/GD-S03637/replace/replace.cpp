#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
	ios::sync_with_stdio(0);
	
    freopen("replace.in", "r", stdin);
    freopen("replace.out", "w", stdout);
    
    int n, q; cin >> n >> q;
    string s1, s2;
    vector<int> s1i(n), s2i(n), l(n);
    for(int j = 0; j < n; ++j) {
    	cin >> s1 >> s2;
    	l[j] = s1.size();
    	for(int k = 0; k < s1.size(); ++k) {
    		if(s1[k] == 'b') {
    			s1i[j] = k;
			}
			if(s2[k] == 'b') {
				s2i[j] = k;
			}
		}
	}
	for(int i = 0; i < q; ++i) {
		cin >> s1 >> s2; int i1, i2;
		int cnt = 0;
		for(int k = 0; k < s2.size(); ++k) {
    		if(s1[k] == 'b') {
    			i1 = k;
    			
			}
			if(s2[k] == 'b') {
				i2 = k;
				
			}
		}
		for(int j = 0; j < n; ++j) {
			if(i1 - i2 == s1i[j] - s2i[j] &&
				i1 >= s1i[j] && s1.size() - i1 >= l[j] - s1i[j] &&
				i2 >= s2i[j] && s2.size() - i2 >= l[j] - s2i[j]) {
				++cnt;
			}
		}
	}

    return 0;
}

