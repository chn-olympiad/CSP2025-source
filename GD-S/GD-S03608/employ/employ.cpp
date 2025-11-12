#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353,N= 1e3;
int vis[N],a[N],c[N];int n,m;
int ans = 0;string s;
void dfs(int u){
	if(u==n+1){
		int t = 0;
		for(int i = 1;i<=n;i++){
			int p = a[i];
			if(t>=c[p]) t++;
			else if(s[i]=='0') t++;
		}
		if(n-t>=m) ans = (ans+1)%mod;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(vis[i]) continue;
		a[u] = i;vis[i] = 1;
		dfs(u+1);
		vis[i] = 0;a[u] = 0;
	}
	return;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;s = ' '+s;
	for(int i = 1;i<=n;i++) cin>>c[i];
	dfs(1);cout<<ans;
	return 0;
}
