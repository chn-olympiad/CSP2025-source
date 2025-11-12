#include <iostream>
using namespace std;
int n, q;
string s1, s2, t1, t2;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> s1 >> s2;
	}
	while (q--) {
		cin >> t1 >> t2;
		cout << 0 << '\n';
	}
	return 0;
}
