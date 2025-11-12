#include <bits/stdc++.h>
#define ll long long
#define Blackdream1853 return
#define code 0
using namespace std;
string s, t;
signed main(void) {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (auto c:s) if (isdigit(c)) t.push_back(c);
	sort(t.begin(),t.end(),greater<char>());
	cout << t << '\n';
	Blackdream1853 code;
}
