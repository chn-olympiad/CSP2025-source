#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5e5;
ll n,k;
ll a[N+5];
ll tr[23*N+5][2];
ll root=1,cnttr=1;
bool vis[23*N+5];
void insert(ll x){
	ll rt=root;
	for(ll i=21;i>=0;i--){
		ll num=((x>>i)&1ll);
		if(!tr[rt][num]) tr[rt][num]=++cnttr;
		rt=tr[rt][num];
	}
	vis[rt]=1;
	return;
}
bool searchh(ll x){
	ll rt=root;
	for(ll i=21;i>=0;i--){
		ll num=((x>>i)&1ll);
		if(!tr[rt][num]) return false;
		else rt=tr[rt][num];
	}
	return vis[rt];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
	ll s=0,ans=0;
	insert(0);
	for(ll i=1;i<=n;i++){
		s^=a[i];
		if(searchh(s^k)){
			ans++;
			root=++cnttr;
			insert(0);
			s=0;
		}
		else insert(s);
	}
	printf("%lld",ans);
	return 0;
}
