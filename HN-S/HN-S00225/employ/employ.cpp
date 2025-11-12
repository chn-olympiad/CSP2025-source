#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int MOD = 998244353;
int n, m, cnt, ans;
bool f0 = 1, f1 = 1;
char c;
signed main(){
  	freopen("employ.in","r",stdin);
  	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> c;
		int a = (c - '0');
		cnt += a;
		if(a == 1)f0 = 0;
		else f1 = 0;
	}
	if(f0){
		cout << 0;
		return 0;
	}
	if(f1){
		ans = 1;
		for(int i = n;i >= n - m - 1;i --){
			ans *= i;
			ans %= MOD;
		}
		cout << ans;
		return 0;
	}
	if(m == 1){
		cout << cnt;
		return 0;
	}
	if(m == n){
		if(cnt == n){
			ans = 1;
			for(int i = n;i >= n - m - 1;i --){
				ans *= i;
				ans %= MOD;
			}
		}
		cout << ans;
		return 0;
	}
	return 0;
}
