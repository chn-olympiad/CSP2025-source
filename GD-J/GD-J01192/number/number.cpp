#include <bits/stdc++.h>
using namespace std;
vector<int> f;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		if (c <= '9' && c >= '0') {
			f.push_back(c - '0');
		}
	}
	sort(f.begin(), f.end());
	for (int i = f.size() - 1; i >= 0; i--){
		cout << f[i];
	}
	return 0;
} 
