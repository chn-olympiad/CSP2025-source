#include<bits/stdc++.h>
using namespace std;
pair<string, string> p;
string s[200005];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	string ss, ss1;
	for (int i=1;i<=n;i++) {
		cin >> s[i] >> ss1;
		p[s[i]]=ss1;
	}
	int ans=0;
	while (q--) {
		cin >> ss >> ss1;
		ans=0;
	}
	return 0;
} 
