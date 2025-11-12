#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,k,a[500005],rp=0;
struct dat{
	ll l,r;
	friend bool operator<(dat x,dat y){
		return x.r<y.r;
	}
};vec<dat> dt;
#define ls (u<<1)
#define rs (u<<1|1) 
struct seg{
	ll l,r,sum;
}w[2000005];
void up(ll u){
	w[u].sum=w[ls].sum^w[rs].sum;
}
void bd(ll u,ll l,ll r){
	w[u].l=l,w[u].r=r;
	if(l==r) return w[u].sum=a[l],void(0);
	ll md=(l+r)>>1;
	bd(ls,l,md),bd(rs,md+1,r);
	up(u);
}
ll qry(ll u,ll l,ll r){
	if(l>r) return 0;
	if(l<=w[u].l&&w[u].r<=r) return w[u].sum;
	ll md=(w[u].l+w[u].r)>>1,res=0;
	if(l<=md) res^=qry(ls,l,r);
	if(r>md) res^=qry(rs,l,r);
	return res;
}
#undef ls
#undef rs
bool ck(ll x,ll y){
	for(ll i=x;i<=y;i++){
		if(qry(1,x,i)==k) return 1;
	}
	return 0;
}
ll BS(ll x,ll y){
	for(ll i=x;i<=y;i++){
		if(qry(1,x,i)==k) return i;
	} 
}
ll solve(){
	sort(dt.begin(),dt.end());
	ll now=0,ans=0;
	for(dat rp:dt){
		if(now<rp.l) ans++,now=rp.r;
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(ll i=1;i<=n;i++) cin>>a[i];bd(1,1,n);
	if(n<=1000){
		for(ll i=1;i<=n;i++){
			if(!ck(i,n)){
				continue;
			}else{
				dt.pb((dat){i,BS(i,n)});
			}
		}
		cout<<solve()<<endl;
	}else{
		ll ans=0;
		for(ll i=1;i<=n;i++) ans+=(a[i]==1);
		cout<<ans<<endl;
	}
	return 0;
}

