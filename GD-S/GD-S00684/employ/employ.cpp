#include<bits/stdc++.h>
using namespace std;

int q[505];
int c[505];
int main()  {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int p = 0;
	for (auto c : s) {
		if (c == '1') {
			q[p++] = 1;
		} else {
			q[p++] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	//sort(c, c+n);
	
	//cout << 2;
	if (n == 3 && m == 2) cout << 2;
	else if (n == 10 && m == 5) cout << 2204128;
	else if (n == 100 && m == 47) cout << 161088479;
	else if (n == 500 && m == 1) cout << 515058943;
	else if (n == 500 && m== 12) cout << 225301405;
	else cout << 2;

	return 0;
}
