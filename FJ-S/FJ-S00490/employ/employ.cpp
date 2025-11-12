#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6 + 5;
const int mod = 998244353;

int n,m,a[505],vis[505],ans,b[505];
string s;

void dfs(int k,int cnt){
//	for(int i=1;i<=k;i++)cout << b[i] << " ";
//	cout << cnt << '\n';
	if(k == n && cnt >= m){
		ans++;
		ans%=mod;
		return;
	}
	if(n-k+cnt < m)return;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i] = true;
			bool flag = 0;
			if(s[k]=='1'&&k-cnt<a[i])flag=1;
			b[k+1] = i;
			dfs(k+1,cnt + flag);
			vis[i] = false;
		}
	}
	return;
}

void solve(){	
	cin >> n >> m >> s;
	for(int i=1;i<=n;i++)cin >> a[i];
	dfs(0,0);
	cout << ans;
	return;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T = 1;
//	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
