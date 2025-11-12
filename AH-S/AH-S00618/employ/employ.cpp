#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
ll ans=1;
bool f;
int n,m,b[505];
char a[505];
bool vis[505];
void dfs(int tot,int cnt){
	if(cnt>=n){
		if(n-tot>=m){
		ans++;
		ans%=mod;
		}
	return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1) continue;
		vis[i]=1;
		if(a[i]=='1') dfs(tot,cnt+1);
		else{
			if(tot>=b[i]) dfs(tot+1,cnt+1);
			else dfs(tot,cnt+1);
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
