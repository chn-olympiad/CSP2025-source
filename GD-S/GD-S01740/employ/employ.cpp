#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998224353;
int ak[30],vis[30],c[501];
char s[501];
int n,m,ans;
void dfs(int x,int fail){
	if(x==n+1){
		if(n-fail>=m) ans++;
		return ;
	}
	if(n-fail+(n-x)<m) return ;
	for(register int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		ak[x]=i;
		if(s[x]=='0'||fail>=c[i]){
			dfs(x+1,++fail);
			--fail;
			vis[i]=0;
		}
		else{
			dfs(x+1,fail);
			vis[i]=0;	
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flagA=1;
	for(register int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') flagA=0;
	}
	for(register int i=1;i<=n;i++) cin>>c[i];
	if(flagA){
		int ans1=1;
		for(register int i=1;i<=n;i++){
			ans1*=i;
			ans1%=mod;	
		}
		cout<<ans1%mod;
		return 0; 
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
