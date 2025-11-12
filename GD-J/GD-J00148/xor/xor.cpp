# include <iostream>
# include <map>
# define FILE
using namespace std;
int n,k,a[500005],pre[500005],dp[500005];
map<int,int> mp;
// xor = k, max_idx = l
void solve(){
	cin >> n >> k;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
		pre[i] = pre[i-1] ^ a[i];
	}for (int i = 1;i <= n;i++){
		if (mp[pre[i] ^ k]) dp[i] = dp[mp[pre[i] ^ k]] + 1;
		if (!mp[0] && pre[i] == k) dp[i] = 1;
		dp[i] = max(dp[i],dp[i-1] + (a[i] == k));
		mp[pre[i]] = i;
	}cout << dp[n] << endl;
}int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    # ifdef FILE
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    # endif
    # ifdef mulq
    int T; cin >> T;
    while (T--) solve();
    # else
    solve();
    # endif
    return 0;
}
