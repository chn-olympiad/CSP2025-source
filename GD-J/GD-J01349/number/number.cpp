#include <bits/stdc++.h>
#define int long long
using namespace std;

string s;

bool cmp(int x, int y) {
	return x > y;
}

signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	cin >> s;
	vector<int> a;
	
	for (int i = 0; i < s.size(); i++) 
		if (s[i] >= '0' && s[i] <= '9') a.push_back(s[i] - '0');
	
	sort(a.begin(), a.end(), cmp);
	
	for (int i = 0; i < a.size(); i++) printf("%lld", a[i]);
	
	return 0;
} 
