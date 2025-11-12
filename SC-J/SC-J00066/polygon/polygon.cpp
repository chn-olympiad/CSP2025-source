#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5,mod=998244353;
ll arr[N];
ll n,ans,mx,nt;

ll tim(ll x){
	ll ret=1;
	for(int i=2;i<=x;i++) ret*=i;
	return ret;
}
ll C(ll m,ll n) {return nt/(tim(m)*tim(n-m));}
void solve1(){
	for(int i=3;i<=n;i++) ans=(ans+C(i,n))%mod;
	return ;
}
void solve2(ll x,ll k,ll sum,ll maxn){
	if(x==n+1){
		if(k<3 || sum<=2*maxn) return ;
		ans++;
		return ;
	}
	solve2(x+1,k+1,sum+arr[x],max(maxn,arr[x]));
	solve2(x+1,k,sum,maxn);
	return ;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		mx=max(mx,arr[i]);
	}
	if(mx==1){
		nt=tim(n);
		solve1();
		cout<<ans;
	}
	else{
		solve2(1,0,0,0);
		cout<<ans%mod;		
	}
	
	return 0;
}