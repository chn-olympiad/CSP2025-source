#include<bits/stdc++.h>
#define endl '\n'
#define MOD 998244353
using namespace std;
long long n, m, ans = 1;
string s;
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	for(int i = 0;i < s.size();i++){
		if(s[i] == '0')
			return cout << m << endl, 0;
	}
	for(long long i = 1;i <= n;i++)
		ans = (ans * i) % MOD;
	cout << ans << endl;
	return 0;
}
