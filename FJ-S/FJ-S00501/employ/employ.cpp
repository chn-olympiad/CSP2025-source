#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,m,c[501],ss;
long long ans,sum;
int s[501],vis[501];
bool k;
void dfs(int x,int y){
	if(x==n){
		if(y>=m) ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			if((x-y)<c[i]&&s[x+1]==1) dfs(x+1,y+1);
			else dfs(x+1,y);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		s[i]=x-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]>0) ss++;
	}
	if(ss<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(s[i]==0) k=1;
	}
	if(k==0){
		for(int i=1;i<=ss;i++) ans=(ans*i)%mod;
		cout<<ans;
	}else{
		dfs(0,0);
		cout<<ans;
	}
	return 0;
}

