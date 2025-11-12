#include<iostream>
using namespace std;
using ll=long long;
const int Mod=998244353;
ll a[5007];
ll n,ans=0;
bool f=0;
void dfs(ll x,ll sum,ll mx,ll cnt){
	if(x>n){
		if(cnt>=3&&sum>2*mx) ++ans;
		 return;
	}
	dfs(x+1,sum+a[x],max(mx,a[x]),cnt+1);
	dfs(x+1,sum,mx,cnt);
}
ll C(ll n,ll m){
	ll nxt=n,sum=1;
	for(int i=1;i<=m;++i){
		sum=sum*nxt/i;
		sum%=Mod;
		nxt--;
	}
	return sum;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(f==0){
		for(int i=3;i<=n;++i) ans=(ans+C(n,i))%Mod;
	}else dfs(1,0,0,0);
	cout<<ans%Mod;
	return 0;
}
