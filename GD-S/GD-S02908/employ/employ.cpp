#include<bits/stdc++.h>
#define int long long
const int N = 505;
const int mod = 998244353;
using namespace std;

int c[N];

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int res = 1;
	for(int i = 1; i <= n; i++){
		res = 1ll * res * i % mod;
	}
	cout << res;
	return 0;
}
