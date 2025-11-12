#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5009,mod=998244353;
ll n,a[maxn];
ll ans=0;
void dfs(ll step,ll sum,ll cnt){
	if(cnt>=3&&sum>a[step]*2){
		ans=(ans+1)%mod;
	}
	for(ll i=step+1;i<=n;++i){
		dfs(i,sum+a[i],cnt+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(ll st=1;st<=n-2;++st){
		dfs(st,a[st],1);
	}
	cout<<ans<<'\n';
	return 0;
}

















