#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define lc p<<1
#define rc p<<1|1
using namespace std;
ll n,a[5100],ans;
struct node{
	ll l,r,maxn,num;
}e[21000];
inline void pushup(ll p){
	e[p].num=e[lc].num+e[rc].num;
	e[p].maxn=max(e[lc].maxn,e[rc].maxn);
	return;
}
inline void build(ll p,ll l,ll r){
	e[p].l=l,e[p].r=r,e[p].num=a[l],e[p].maxn=a[l];
	if(l==r)return;
	ll m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
	return;
}
inline pair<ll,ll> query(ll p,ll l,ll r){
	if(e[p].l>=l&&e[p].r<=r){
		return make_pair(e[p].maxn,e[p].num);
	}
	ll m=e[p].l+e[p].r>>1,maxn=-1e18,num=0;
	if(l<=m){
		auto t=query(lc,l,r);
		maxn=max(t.first,maxn);
		num+=t.second;
	}
	if(r>m){
		auto t=query(rc,l,r);
		maxn=max(t.first,maxn);
		num+=t.second;
	}
	return make_pair(maxn,num);
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	build(1,1,n);
	for(ll i=1;i<=n-2;++i){
		for(ll j=i+2;j<=n;++j){
			auto t=query(1,i,j);
			ll maxn=t.first,tt=t.second;
			if(maxn*2<tt){
				ans++;
				ans%=mod;
				ll xd=tt-maxn*2;
				ll wz=lower_bound(a+i,a+j,xd)-a-1;
				if(wz-i>0){
					ans+=wz-i;
					ans%=mod;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
hua-love×¨Êô
hua-love ´óÀÐorz 
*/
