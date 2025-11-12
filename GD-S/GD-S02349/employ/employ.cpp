#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
using namespace std;
ll n,m;
char s[510];
ll c[510];
ll a[510],cnt=0;
bool vis[510];
void dfs(ll now,ll likai){
	if(n-likai<m) return;
	if(now>n){
		if(n-likai>=m) cnt=(cnt+1)%mod;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;
		if(s[now]=='0'||likai>=c[i]) dfs(now+1,likai+1);
		else dfs(now+1,likai);
		vis[i]=false;
	}
}
void solve1(){
	dfs(1,0);
	printf("%lld",cnt%mod);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	solve1();
	return 0;
}
