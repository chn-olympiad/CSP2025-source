//GZ-S00017 贵阳市第一中学 伍星恒 
#include <bits/stdc++.h>
using namespace std;
int n, m, cnt1=0;
char s[501];
int c[501];
bool flag = true;
const int mod = 998244353;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> s[i];
		s[i] -= '0';
		flag = flag && s[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		if (!c[i]){
			cnt1++;
		}
	}
	if(m == 1){
		int ans = 1;
		for(int i = 1; i <= n-1; i++){
			ans *= i;
			ans %= mod;
		}
		ans *= n-cnt1;
		ans %= ans;
		cout << ans;
		return 0;
	}
	if (cnt1 >= n-m){
		cout << 0;
	}
	else
	{
		int ans = 1;
		for(int i = 1; i <= n; i++){
			ans *= i;
			ans %= mod;
		}
		cout << ans;
	}
	return 0;
}
