#include<cstdio>
#include<iostream>
using namespace std;

const int mod=998244353;

int n,m;
char s[114];
int c[114];
bool vis[114];
long long ans;

void dfs(int dep,int refused,int hired){
	if(dep>n){
		if(hired>=m) ans++,ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(refused>=c[i]||s[dep]=='0') dfs(dep+1,refused+1,hired);
		else dfs(dep+1,refused,hired+1);
		vis[i]=false;
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1,0,0);
	cout<<ans;
	return 0;
}