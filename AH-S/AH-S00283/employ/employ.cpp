#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],p[505],ans,vis[505];
void dfs(int now,int fa){
	if(fa>n-m){
		return;
	}
	if(now>n){
		ans++;
		return;
	}
	for(int i = 1;i<=n;i++){
		if(!vis[i]){
			vis[i] = 1;
			dfs(now+1,fa+(fa>=p[i] || !a[now]));
			vis[i] = 0;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		char c;
		cin>>c;
		a[i] = c-'0';
	}
	for(int i = 1;i<=n;i++){
		cin>>p[i];
	}
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
