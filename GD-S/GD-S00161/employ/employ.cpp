#include<bits/stdc++.h>
#define N 100005
using namespace std;
int vis[N],c[N],n,m,ans;
string s;
inline void dfs(int x,int p){
	if(n-p<m) return;
	if(x>n&&n-p>=m) return ans++,void();
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(s[x]=='0'){
			dfs(x+1,p+1);
		}
		else{
			if(p>=c[i]) dfs(x+1,p+1);
			else dfs(x+1,p);			
		}
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;s=' '+s;
	if(n>10){cout<<0;return 0;}
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

*/
