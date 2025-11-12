#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string t;
	vector <char> a; 
	cin >> t;
	for (char p : t)
		if (isdigit(p))
			a.push_back(p);
	sort(a.begin(), a.end(), greater <char>());
	for (char p : a)
		cout << p;
	cout << '\n';
	return 0;
}
