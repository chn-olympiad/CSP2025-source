#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=998244353;
ll n;
ll a[5005];
ll b[5005];
ll ans;
bool f[5005];
ll ma;
void dfs(ll dep,ll sum,ll k,ll t){
	if(dep==t){
		if(sum>ma*2) ans=(ans+1)%M;
		return;
	}
	for(int i=k;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			ll ls=ma;
			ma=max(ma,a[i]);
			dfs(dep+1,sum+a[i],i,t);
			f[i]=0;
			ma=ls;
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
	for(ll i=3;i<=n;i++){
		dfs(0,0,1,i);
		memset(f,0,sizeof(f));
	}
	cout<<ans;
	return 0;
}