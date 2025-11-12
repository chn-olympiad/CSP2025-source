#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
vector<pair <string,string>> k;
void solve () {
	int n,q;
	cin >> n >> q;
	string l1,l2;
	for (int i = 1; i <= n ; i ++){
		cin >> l1 >> l2 ; k.push_back ({l1, l2});
	}
//	cout <<1;
	while (q--) {
		cin >> l1 >> l2;
		int cnt=0;
		cout << cnt << endl;
	}
}

signed main () {
//	ios :: sync_with_stdio (false), cin.tie (0), cout.tie (0);
//	freopen ("replace1.in", "r", stdin);
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	solve ();

	return 0;
}

