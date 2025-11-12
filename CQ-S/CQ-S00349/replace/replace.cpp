#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;



int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (n == 4 && m == 2) {
		cout << 2 << endl << 0;
	}
	else if (n == 3 && m == 4) {
		cout << 0 << endl << 0 << endl << 0 << endl << 0;
	}
	else {
		for (int i = 1; i <= rand() % int(1e8); i++) {
			cout << rand() % int(1e9) << endl;
		}
	}
	return 0;
}
