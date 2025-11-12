#include <bits/stdc++.h>
using namespace std;
string s;
vector<int> a;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	for(int i = 0; i < s.length(); i++){
		if(s[i] >= '0' && s[i] <= '9') a.push_back(s[i] - '0');
	}
	
	sort(a.rbegin(), a.rend());
	for(int i : a) cout << i;
	return 0;
} 
