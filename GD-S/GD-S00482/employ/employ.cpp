#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=510;
const ll mod=998244353;
ll n,m,s[N],c[N];
bool check(){
	for(int i=1;i<=n;i++)if(s[i]!=1)return false;
	return true;
}
ll fastpow(ll x,ll y){
	ll res=1;
	while(y){
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll fac[N],inv[N];
void solve(){
	fac[0]=1ll;
	for(ll i=1;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	cout<<fac[n];
	return;
}
int P[N],cnt=0,vis[N],ans=0;
bool check2(){
	int dnt=0,tot=0;
	for(int i=1;i<=n;i++){
		int x=P[i];
		if(c[x]<=dnt){
			dnt++;continue;
		}
		if(s[i]==0)dnt++;
		else tot++;
	}
	return tot>=m;
}
void dfs(int now){
	if(now==n){
		if(check2())ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			P[now+1]=i;vis[i]=1;
			dfs(now+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		if(ch=='0')s[i]=0;
		else s[i]=1;
	}
	for(int i=1;i<=n;i++)cin>>c[i];
	if(check())solve();
	else{
		dfs(0);
		cout<<ans<<"\n";
	}
	return 0;
}

