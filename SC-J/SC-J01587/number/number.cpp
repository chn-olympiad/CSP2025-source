#include <iostream>
using namespace std;
int a[10];
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	for(int i = 0; i < s.length(); i++) {
		if(s[i] <= '9' && s[i] >= '0'){
			a[s[i]-'0']++;
		}
	}
	for(int i = 9; i >= 0; i--) {
		for(int j = 1; j <= a[i]; j++) {
			cout << i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}