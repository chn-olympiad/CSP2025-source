#include<bits/stdc++.h>
using namespace std;
string s;
int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	cin >> s;
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	for(auto i : s) {
		if(i >= '0' && i <= '9') {
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
