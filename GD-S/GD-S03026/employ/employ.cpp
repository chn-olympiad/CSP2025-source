#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m;
bool vis[19];
int a[19];
int b[19];
int bb;
int ans;
string s;
void dfs(int k){
	if(k == n+1){
		int losr = 0;
		for(int i = 1;i<=n;++i){
			if(s[i] == '0') losr++;
			else if(losr>=a[b[i]]) losr++;
		}
		if(n-losr>=m) ans++;
		return ;
	}
	for(int i = 1;i<=n;++i){
		if(!vis[i]){
			vis[i] = 1;
			b[++bb] = i;
			dfs(k+1);
			--bb;
			vis[i] = 0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(n<=10){
		cin>>s;
		s = '#'+s;
		for(int i = 1;i<=n;++i) cin>>a[i];
		dfs(1);
		cout<<ans;
	}
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
}
