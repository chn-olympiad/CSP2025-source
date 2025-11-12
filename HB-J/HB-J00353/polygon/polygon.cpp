#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
const int N = 25;
int a[N],n,ans;
bool vis[N];
void dfs(int pos,int tot,int mx,int limit,int hav){
	if(hav == limit){
		if(tot > 2*mx) ans = (ans+1)%MOD;
		return;
	}
	if(pos == n+1) return;
	for(int i = pos;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		int tmp = max(a[i],mx);
		dfs(i+1,tot+a[i],tmp,limit,hav+1);
		vis[i] = 0;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int num = 3;num <= n;num++) dfs(1,0,0,num,0);
	cout << ans;
	return 0;
}