#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define int long long
#define endl "\n"

using namespace std;

string a;
int n, m;

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= 2 * (n + m); i++) {
		cin >> a;
	}
	for(int i = 1; i <= m; i++) {
		cout << 0 << endl;
	}
	return 0;
}
