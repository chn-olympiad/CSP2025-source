#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
int vis[505];
char c[505];
int ans;
void dfs(int sz,int nw){
	if(n-nw<m) return ;
	if(sz==n+1){
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(c[sz]=='0'||nw>=a[i]) dfs(sz+1,nw+1);
		else dfs(sz+1,nw);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> c[i];
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1,0);
	cout << ans << '\n';
	return 0;
}
