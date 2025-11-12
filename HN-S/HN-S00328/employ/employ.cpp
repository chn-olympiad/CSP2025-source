#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
string s;
int c[20];
bool vis[20];
int n,m;
int cnt,ans;
void dfs(int u){
	if(u>n){
		ans+=(cnt>=m);
		ans%=mod; 
		return; 
	}
	for(int i=1;i<=n;i++){
		if(vis[i]){
			continue;
		}
		vis[i]=1;
		if(u-1-cnt>=c[i]|| s[u]=='0'){
			dfs(u+1);
		}else{
			cnt++;
			dfs(u+1);
			cnt--;
		}
		vis[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
