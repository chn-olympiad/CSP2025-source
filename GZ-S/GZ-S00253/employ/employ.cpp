//杜泽煊 GZ-S00253 贵阳市华麟学校
#include <bits/stdc++.h>
#define int long long
#define PII pair<int, int>
using namespace std;
const int MAXN = 1e5+5;
const int MAXT = 20;
const int MOD = 998244353;
int n, m;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int>c(n+1);
	for(int i =1; i <= n; i++) {
		cin >> c[i];
	}
	int cnt =0;
	do {
		for(int i = 1; i <= 5; i++) {
			cnt ++;
		}
	} while(next_permutation(c.begin(),c.end()));
	cout << cnt % MOD;
	return 0;
}

