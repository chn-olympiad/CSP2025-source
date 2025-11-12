#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string a;
	cin >> a;
	for(int i = 0; i < a.size(); i++) {
		bool f = 1;
		if(a[i] >= '0' && a[i] <= '9')	f = 0;
		if(f) {
			a.erase(i, 1);
			i--;
		}
	}
	sort(a.begin(), a.end(), greater<char>());
	cout << a << '\n';
	return 0;
}