#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5010],n,ans;
void dfs(ll cur,ll cnt,ll maxn,ll sum){
	if(n - cur + 1 + cnt < 3){
		return;
	}
	if(cur > n){
		if(maxn * 2 < sum){
			ans++;
			ans %= 998244353;
		}
		return;
	}
	dfs(cur + 1,cnt + 1,max(maxn,a[cur]),sum + a[cur]);
	dfs(cur + 1,cnt,maxn,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
	}
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
