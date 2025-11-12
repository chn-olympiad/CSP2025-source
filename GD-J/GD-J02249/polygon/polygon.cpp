#include <iostream>
using namespace std;
#define int long long
const int mod = 998244353;
int n,len[5005],ans;
void dfs(int u,int sum,int ml){
	if (u == n+1){
		if (sum > ml*2){
			ans++;
			ans %= mod;
		}return;
	}
	dfs(u+1,sum+len[u],max(ml,len[u]));
	dfs(u+1,sum,ml);
	return;
}int tmie(int n){
	if (n == 1) return 1;
	return tmie(n-1)*2%mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	int mm = 0,maxlen = 0;
	for (int i = 1;i <= n;i++){
		cin >> len[i];
		maxlen = max(maxlen,len[i]);
	}if (maxlen == 1){
		cout << (tmie(n)-n-((n-1)*n/2)%mod-1+mod*mod)%mod;
		return 0;
	}
	dfs(1,0,0);
	cout << ans;
	return 0;
} 
