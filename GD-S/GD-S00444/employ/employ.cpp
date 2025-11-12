#include<bits/stdc++.h>
using namespace std;
int n,m,ans,c[1000];
bool vis[1000];
string s; 
void dfs(int step,int cnt){
	if(step>n){
		if(n-cnt>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		vis[i]=1;
		if(s[i]!='0'||cnt>=c[i])cnt++;
		dfs(step+1,cnt);
		if(s[i]!='0'||cnt>=c[i])cnt--;
		vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	dfs(1,0);
	cout<<ans;
	return 0;
}

