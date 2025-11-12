#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
const int mod = 998244353;
int n, m;
int c[N], p[N];
char s[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
//	int tot1 = 0;
	for(int i = 1; i <= n; i ++){
		cin >> s[i];
		if(s[i] == '0') flag = false;
	}
	int tot = 0;
	for(int i = 1; i <= n; i ++){
		cin >> c[i];
		tot += (c[i] != 0);
		p[i] = i;
	}
	if(n <= 10){
		int ans = 0;
		do{
			int cn1 = 0, cn2 = 0;
			for(int i = 1; i <= n; i ++){
				if(cn1 >= c[p[i]]){
					cn1 ++;
					continue;
				}
				if(s[i] == '0'){
					cn1 ++;
				}
				else{
					cn2 ++;
				}
			}
			ans += (cn2 >= m);
			ans %= 998244353;
		}while(next_permutation(p + 1, p + n + 1));
		cout << ans;
		return 0;
	}
	if(flag){
//		cout << tot << "\n";
		if(tot + 1 < m) cout << 0;
		else if(tot + 1 == m){
			long long ans = 1;
			for(int i = 1; i < n; i ++){
				ans = (ans * 1ll * i) % mod;
			}
			cout << 1ll * (n - tot) * ans;
		}
		else{
			long long ans = 1;
			for(int i = 1; i <= n; i ++){
				ans = ans * 1ll * i % mod;
			}
			cout << ans;
		}
		return 0;
	}
	return 0;
} 
