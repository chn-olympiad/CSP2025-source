#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll a[10101],s[10101],ans[10101],pr[10101],ans2;
ll kpow(ll b){
	if(pr[b]) return pr[b];
	ll res=1,a=2;
	while(b){
		if(b&1) res*=a,res%=mod;
		b=b/2,a=a*a,a%=mod;
	}
	pr[b]=res;
	return res;
}
ll n,maxn=-1;
void dfs(ll now,ll sum){
	if(now==n+1) return;
	if(sum>a[now]) ans2++;
	dfs(now+1,sum+a[now]);
	dfs(now+1,sum);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i],maxn=max(maxn,a[i]);
	sort(a+1,a+n+1);
	if(maxn==1){
		ll ans1=0;
		for(ll i=3;i<=n;i++){
			ans1+=kpow(i);
			ans1-=(1+i+i*(i-1)/2);
			ans1%=mod;
		}
		cout<<ans1;
		return 0;
	}
	else{
		dfs(1,0);
		cout<<ans2;
	}
	return 0;
}