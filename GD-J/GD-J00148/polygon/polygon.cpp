# include <iostream>
# define FILE
# define BRUTE_FORCE
# define ll long long
using namespace std;
const ll mod = 998244353;
int n; ll ans,a[5005];
void dfs(int cur,int cnt,ll sum,ll mx){
	if (cur > n){
		if (cnt >= 3 && sum > 2 * mx) ans++,ans %= mod;
		return;
	}dfs(cur + 1,cnt,sum,mx),dfs(cur + 1,cnt + 1,sum + a[cur],max(mx,a[cur]));
}void solve(){
	cin >> n;
	ll mx = 0;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		mx = max(mx,a[i]);
	}if (mx == 1){
		for (int edg = 3;edg <= n;edg++){
			ll cur = 1ll * (n - edg + 1) * (n - edg + 2) / 2ll;
			(ans += cur) %= mod;
		}cout << ans << endl;
	}else if (n <= 20){
		dfs(1,0,0ll,0ll);
		cout << ans << endl;
	}else{
		dfs(1,0,0ll,0ll);
		cout << ans << endl;
	}
}int main(){
    # ifdef FILE
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    # endif
    # ifdef mulq
    int T; cin >> T;
    while (T--) solve();
    # else
    solve();
    # endif
    return 0;
}
