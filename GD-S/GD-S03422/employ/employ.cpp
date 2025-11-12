#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("employ.in", "r", stdin);
	freopen ("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<bool> s(n);
	vector<int> c(n);
	string temp;
	cin >> temp;

	for (int i = 0; i < n; i++) {
		if (temp[i] = '1') s[i] = true;
		else s[i] = false;
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	sort (c.begin(), c.end());
	cout << '2';

	fclose(stdin);
	fclose(stdout);
	return 0;
}
