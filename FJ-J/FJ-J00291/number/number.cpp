#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.size();
	s = ' ' + s;
	vector <int> mp(20);
	for(int i = 1;i <= n;i++) {
		if(isdigit(s[i])) mp[s[i] - '0']++;
	}
	for(int i = 9;i >= 0;i--) {
		for(int j = 1;j <= mp[i];j++){
			cout << i;
		}
	}
	cout << "\n";
	return 0;
}
