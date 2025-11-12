#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool cmp(char a, char b) {
	return a>b;
}
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	string d = "";
	for(int i = 0; i < s.size(); i ++) {
		if(s[i] >= '0' && s[i] <= '9') {
			d += s[i];
		}
	}
	sort(d.begin(), d.end(), cmp);
	cout << d;
	return 0;
}