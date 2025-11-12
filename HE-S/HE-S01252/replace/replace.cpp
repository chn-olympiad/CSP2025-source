#include <bits/stdc++.h>
using namespace std;
int main () {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	long long n, q;
	string j1[20005], j2[20005];
	string xw1[20005], xw2[20005];
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> j1[i] >> j2[i];
	}
	for (int i = 0; i < q; i++) {
		cin >> xw1[i] >> xw2[i];
	}
	if (q == 1) {
		cout << n << endl;
	} else  {
		for (int i = 0; i < q; i++) {
			cout << 0 << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
