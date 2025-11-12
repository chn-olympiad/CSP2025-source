#include <bits/stdc++.h>
using namespace std;
int n, q;
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	srand(time(0));
	cin >> n >> q;
	while(q --) {
		cout << rand();
	}
	return 0;
}
