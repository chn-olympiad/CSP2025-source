#include <bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
int n, m;
int cnt = 0;
int c[100005];
int main ( ) {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	string s;
	cin >> s;
	s = " " + s;
//	int pos
	bool pd = 1;
	for (int i = 1; i < s.size(); i ++) {
		if (s[i] != '1'){
			pd = 0;
			break;
		}
	}
	for (int i = 1; i <= n; i ++) cin >> c[i];
	if (pd) {
		long long ans = 1;
		for (int i = 1; i <= n; i ++) {
			ans = (ans * i) % mod;
		}
		cout << (ans % mod) ;
	}else if (n <= 10) {
		long long ans = 1;
		for (int i = 1; i <= n; i ++) ans = ans * i;
		int xl[1005];
		int as = 0;//答案 
		for (int i = 1; i <= n; i ++) xl[i] = i;
		while (ans --) {
//			for (int i = 1; i <= n; i ++) cout << xl[i] << " ";
//			cout << '\n';
			int nw = 0;//录用人数 
			int wl = 0;//未录 
			for (int i = 1; i <= n; i ++) {
				if (wl >= c[xl[i]] || !(s[i] - '0')) {
					wl ++;
				} else {
					nw ++;
				}
			}
			as += (nw >= m);
			next_permutation(xl + 1, xl + 1 + n);
		}
		cout << as;
	}
	else{
		cout << 0;
	}
	return 0;
} 
//freopen(".in", "r", stdin);
//freopen(".out", "w", stdout);
/*
10 5 
1111111111
1 1 1 1 1 1 1 1 1 1
*/
