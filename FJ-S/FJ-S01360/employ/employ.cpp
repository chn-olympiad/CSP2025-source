#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, q; cin >> n >> q;
	int up = 1;
	for (int i = 1; i <= n; ++i) up *= i;
	srand(time(NULL));
	cout << rand() % up << endl;
	return 0;
}

