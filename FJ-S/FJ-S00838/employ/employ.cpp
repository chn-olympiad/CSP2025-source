#include<bits/stdc++.h>
using namespace std;
const int N=100,MOD=998244353;
bool vis[N],s[N];
int c[N],ans,n,m;
void dfs(int x,int cnt){
	if(x==n+1){
		if(n-cnt==m) ans++,ans%=MOD;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		if(cnt>=c[i]) dfs(x+1,cnt+1);
		else dfs(x+1,cnt+(s[x+1]));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string ss;
	cin>>ss;
	for(int i=0;i<ss.size();i++){
		s[i+1]=ss[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
