#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,dp[505][505],c[505],m,ans;
string str;
int vis[100005];
void dfs(int x,int s){
	if(x>n){
		if(s>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		dfs(x+1,s+(str[x-1]=='1'&&x-s-1<c[i]));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>str;
	for(int i=1;i<=n;i++)cin>>c[i];
	int flag=0;
	for(int i=0;i<(int)str.size();i++){
		if(str[i]=='0'){
			flag++;
		}
	}
	if(n<=13){
		dfs(1,0);
		cout<<ans;
		return 0;
	}
	int maxn=0;
	int l=0;
	for(int i=1;i<=n;i++){
		if(c[i])l++;
		maxn=max(maxn,c[i]);
	}
	int p=n+1;
	for(int i=0;i<(int)str.size();i++){
		if(str[i]=='0'){
			p=i+1;
			break;
		}
	}
	if(maxn>p){
		int x=1;
		for(int i=1;i<=l;i++)x=x*i%mod;
		cout<<x;
	}else cout<<0;
	return 0;
}
