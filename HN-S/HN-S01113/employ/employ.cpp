#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N = 505;
const int KMod = 998244353;
int n, m, c[N], p[N], cnt, ans;
string s;
signed main (){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1; i <= n; ++ i){
		p[i] = i;
		cin >> c[i];
	}
	s = ' ' + s;

	do{
		cnt = 0;
		for (int i = 1; i <= n; ++ i){
			if (cnt >= c[p[i]]){
				++ cnt;
				continue;
			}
			if (s[i] == '0') ++ cnt;
		}
		cnt = n - cnt;
		if (cnt >= m){
			ans = (ans + 1ll) % KMod;
		}
	}while(next_permutation(p + 1, p + n + 1));
	cout << ans % KMod << '\n';
	
	return 0;
}
