#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 998244353;
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	bool xz_A = 1;
	string s; cin >> s;
	for (auto &i : s) {
		if (i == '0')
		   xz_A = 0;
	}
    if (xz_A) {
    	ll ans = 1;
    	for (int i = 1; i <= n; i ++)
    		ans = ans * i % mod;
   		cout << ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
   	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
