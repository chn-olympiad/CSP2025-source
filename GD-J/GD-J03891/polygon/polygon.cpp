#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7,mod=998244353;
ll n,ans,a[maxn],f[maxn];
bool vis[maxn];
void dfs(ll x,ll m,ll lst){
	if(x>m){
		ll s=0,mx=-1;
		for(ll i=1;i<=m;i++){
			s+=f[i];
			mx=max(mx,f[i]);
		}
		if(s>mx*2){
			ans=(ans+1)%mod;
		}
		return;
	}
	for(ll i=lst;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			f[x]=a[i];
			dfs(x+1,m,i);
			vis[i]=false;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	for(ll i=1;i<=n;i++){
		dfs(1,i,1);
	}
	cout<<ans%mod<<endl;
	return 0;
}
