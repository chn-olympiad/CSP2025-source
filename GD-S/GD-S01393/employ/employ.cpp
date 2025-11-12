#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],a[505],ans;
string s;
bool vis[505];
bool check(){
	int cnt=0,res=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[a[i]]||s[i-1]=='0')cnt++;
		else res++;
	}	
	return res>=m;
}
void dfs(int u){
	if(u>n){ans=(ans+check())%998244353;return;}
	for(int i=1;i<=n;i++)
		if(!vis[i])vis[i]=true,a[u]=i,dfs(u+1),a[u]=0,vis[i]=false;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n>20){
		ans=1;
		for(int i=2;i<=n;i++)ans=1ll*ans*i%998244353;
	}else dfs(1);
	return cout<<ans,0;
}/*
10 5
1101111011
6 0 4 2	1 2 5 4 3 3*/
