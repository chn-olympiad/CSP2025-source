#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;
string s;
int n, m;

signed main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	int ans = 1;
	while(n != 0){
		ans *= n;
		ans %= mod;
		n--;
	}
	cout << ans;
	return 0;
}

