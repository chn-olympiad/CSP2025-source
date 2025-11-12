#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,c[505],ans;
string s;
void dfs(bool vis[],LL fal,LL cnt,LL sec){
	if(fal>n-m) return ;
	if(sec>=m) ans=(ans+1)%998244353;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			if(s[cnt]=='0'||fal>=c[i]) dfs(vis,fal+1,cnt+1,sec);
			else dfs(vis,fal,cnt+1,sec+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	bool vis[505]={};
	dfs(vis,0,0,0);
	cout<<ans;
	return 0;
}

