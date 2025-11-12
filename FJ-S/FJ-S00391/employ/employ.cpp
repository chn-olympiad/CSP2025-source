// csp-s T1 club
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve(){
	int n, m;cin>>n>>m;
	if (m==1){
		bool flg = 0;
		for (int i=1;i<=n;i++){
			char tmp;cin>>tmp;
			if (tmp == '0') flg=1;
			if (flg) break;
		}
		ll ans = 1;
		if (flg){
			for (int i = 2;i<=n;i++){
				ans = (ans*i) % 998244353;
			}
		}else{
			ans = 0;
		}
		cout<<ans<<endl;
	}else{
		ll ans = 1;
		for (int i = 2;i<=n;i++){
			ans = (ans*i )% 998244353;
		}
		cout<<ans<<endl;
	}
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int T = 1;
	while (T--){
		solve();
	}
	return 0;
}


