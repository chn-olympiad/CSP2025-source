#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;
char ch[maxn];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	string s;
	cin >> s;
	int len = s.size(), tot = 0;
	for(int i=0; i<len; i++) {
		if(s[i] >= '0' && s[i] <= '9') {
			ch[++tot] = s[i];
		}
	}
	sort(ch+1, ch+tot+1);
	for(int i=tot; i>=1; i--) {
		cout << ch[i];
	}
	return 0;
}
