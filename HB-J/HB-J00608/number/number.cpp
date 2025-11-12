#include <bits/stdc++.h>
using namespace std;
int main () {
	string s;
	int max_s = 0;
	cin >> s;
	for (int i : s) {
		max_s = max (max_s, s);
	}
	cout << max_s;
	
	return 0;
}
