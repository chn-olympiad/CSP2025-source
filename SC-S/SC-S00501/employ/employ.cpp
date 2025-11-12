#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s[505],c[505],ans,jc[505],vis[505];
void dfs(int id,int mx,int fq){
	if(id>n){
		if(mx>=m){
			ans++;
			ans%=9982443553;
		}
		return;
	}
	if(mx+n-id+1<m){
		return;
	}
	if(mx>=m){
		ans+=jc[n-id+1];
		ans%=9982443553;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		if(c[i]>fq&&s[id]==1){
			dfs(id+1,mx+1,fq);
		}else{
			dfs(id+1,mx,fq+1);
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	jc[1]=1;
	for(int i=2;i<=n;i++){
		jc[i]=i*jc[i-1];
		jc[i]%=9982443553;
	}
	dfs(1,0,0);
	cout<<ans%9982443553;
	return 0;
}
