#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int n, q;
string a[N][5];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2];
	while (q--) {
		string x, y;
		int ans = n;
		cin >> x >> y;
		int lx = x.size(), ly = y.size();
		if (lx != ly) cout << "0\n";
		else {
			for (int i = 1; i <= n; i++) {
				int itx = x.find(a[i][1]), ity = y.find(a[i][2]);
				if (itx == -1 || ity == -1) ans--;
				else {
					string xx = x.substr(0, itx);
					itx += a[i][1].size();
					string zz = (itx < lx ? x.substr(itx, lx - itx) : "");
					string yy = xx + a[i][2] + zz;
					ans -= yy != y;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
