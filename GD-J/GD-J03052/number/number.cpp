#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6+10;
string s;
int mp[105];
signed main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i]>='0' && s[i]<='9') mp[s[i]-'0'] ++;
	}
	for (int i = 9; i >= 0; i --) {
		for (int j = 1; j <= mp[i]; j ++) cout << i;
	}
	return 0;
}
