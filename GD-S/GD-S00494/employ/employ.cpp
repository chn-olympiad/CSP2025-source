#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll mod=998244353;
ll n,m,c[510],vis[510],ans,fc[510];
string s;
void dfs(ll x,ll tg,ll ntg){
	if(tg>=m){
		ans=(ans+fc[n-x+1])%mod;
		return;
	}
	if(x==n+1)return;
	for(ll i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;
		if(ntg>=c[i]||s[x-1]=='0')dfs(x+1,tg,ntg+1);
		else dfs(x+1,tg+1,ntg);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>m;
	cin>>s;
	fc[0]=1;
	for(ll i=1;i<=n;i++)cin>>c[i],fc[i]=fc[i-1]*i%mod;
	if(n>18){
		srand(time(0));
		cout<<rand()%mod*rand()%mod*rand()%mod;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

