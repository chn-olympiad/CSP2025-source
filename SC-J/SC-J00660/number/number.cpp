#include <bits/stdc++.h>
using namespace std;
#define ll long long;
#define endl '\n'

string s, r;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> s;
	for(int i = 0; i < s.size(); i++)
		if('0' <= s[i] && s[i] <= '9') r += s[i];
	sort(r.begin(), r.end(), greater<int>());
	cout << r;
	return 0;
} 