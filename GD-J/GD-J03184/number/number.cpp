//I love CCf forever!
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[20];
signed main(){
	cin.tie(0) -> sync_with_stdio(0);
	freopen("number.in" , "r" , stdin);
	freopen("number.out" , "w" , stdout);
	
	string s;
	cin >> s;
	s = ' ' + s;
	
	for (int i = 1 ; i <= s.size() ; i++) {
		if (s[i] >= '0' && s[i] <= '9') 
			a[s[i] - '0']++;
	}
	
	for (int i = 9 ; i >= 0 ; i--) {
		while (a[i]) {
			cout << i;
			a[i]--;
		}
	}
	
	return 0;
}
//I love CCf forever!

