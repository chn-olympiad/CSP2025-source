#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 988244353;
int n,m;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	if(n == m) cout << 1;
	else if(m == 1){
		int ans = 1;
		for(int i = 1; i <= n; i++) ans = ans * i % MOD;
		cout << ans;
	}
	else cout << n * m;
	return 0;
}
