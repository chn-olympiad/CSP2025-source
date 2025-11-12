#include<bits/stdc++.h>
using namespace std;
int n,m,c[502],vis[502],ans,f,cnt;
string s;
void dfs(int x,int y){//第几个，已淘汰几人 
	if(x>n){
		if(n-y>=m)ans=(ans+1)%998244353;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[x-1]=='0'||c[i]<=y)dfs(x+1,y+1);
			else dfs(x+1,y);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')f=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i],cnt+=(!c[i]);
	if(!f&&n-cnt<m){cout<<0;return 0;}
	dfs(1,0);
	cout<<ans;
	return 0;
}
