#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int n,m,a[505],id[505];
string s;
bool flag = 1,f = 1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m >> s;
	s = 'b' + s;
	for (int i = 1; i <= n; i++){
		flag &= s[i] == '1';
		cin >> a[i];
		f &= bool(a[i]);
		id[i] = i;
	}
	if (n == m && (!flag || !f)){
		cout << 0;
		return 0;
	}
	if (flag && f){
		long long ans = 1,cnt = 0;
		for (int i = 1; i <= n; i++){
			cnt += bool(a[i]);
			ans = ans * i % mod;
		}
		cout << (cnt >= m ? ans : 0);
		return 0;
	}
	if (m == 1){
		int num = 0,minus = 0;
		long long ans = 1,res = 1;
		for (int i = 1; i <= n; i++) ans = ans * i % mod;
		for (int i = 1; i <= n; i++){
			if (s[i] == '0') res = res * (++num) % mod;
			else{
				int cnt = 0;
				for (int j = 1; j <= n; j++) cnt += a[j] <= i - 1;
				res = res * (cnt - minus++) % mod;
			}
		}
		cout << (ans + mod - res) % mod;
		return 0;
	}
	long long ans = 0;
	do{
		int res = 0,cnt = 0;
		for (int i = 1; i <= n; i++){
			res += s[i] == '1' && cnt < a[id[i]];
			cnt += s[i] == '0' || cnt >= a[id[i]];
		}
		ans = (ans + (res >= m)) % mod;
	}while (next_permutation(id + 1,id + n + 1));
	cout << ans;
	return 0;
}
