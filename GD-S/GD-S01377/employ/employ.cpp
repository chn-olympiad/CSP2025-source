#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;
int n,m,c[N];
string s;
int p[N],vis[N],ans,fac[N];
void dfs(int cur,int get,int ban) {
	if(n-cur+1+get<m) return ;
	if(get>=m) {
		ans=ans+fac[n-cur+1],ans%=mod;
		return ;
	}
	if(cur==n+1) return ;
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		vis[i]=true; p[cur]=i;
		if(ban>=c[p[cur]]) dfs(cur+1,get,ban+1);
		else if(s[cur-1]=='1') dfs(cur+1,get+1,ban);
		else if(s[cur-1]=='0') dfs(cur+1,get,ban+1);
		vis[i]=false;
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	fac[0]=1;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	dfs(1,0,0);
	cout<<ans%mod;
}
/*
5 2
11111
0 1 2 0 2
*/
