#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=510;
int n,m,c[N],ans,a[N];
string s;
bool vis[N];
void check(){
	int ok=0,nok=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0') nok++;
		else{
			if(nok>=c[a[i]]) nok++;
			else ok++;
		}
	}
	if(ok>=m) ans++;
}
void dfs(int x){
	if(x==n+1){
		check();
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			a[x]=i;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
