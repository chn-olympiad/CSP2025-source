#include <bits/stdc++.h>
#define int long long
using namespace std;
const int Max = 5009;
const int Mod = 998244353;
int n,m,ans = 1;
string s;
int c[Max];
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	int nn = n;
	cin >> s;
	for(int i = 1;i <= n;i++) {
		cin >> c[i];
		if(c[i] == 0) nn--;
	}
	if(nn < m) {
		cout << 0;
		return 0;
	}
	for(int i = n;i >= 1;i--) {
		ans = ans * i % Mod;
	}
	cout << ans;
	return 0;
}
