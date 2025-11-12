#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#define lc u<<1
#define rc u<<1|1
using namespace std;
typedef long long ll;
const int N=5e5+5;
struct Tree{
	ll l,r,sum,add;
}tr[N<<2];
ll n,a[N],k,ans,d[N];
ll cnt,cntt;
int f=1;
void pushup(int u){
	tr[u].sum=tr[lc].sum^tr[rc].sum;
}
void build(ll u,ll l,ll r){
	tr[u]={l,r,a[l],0};
	if(l==r) return;
	ll m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(u);
}
ll query(ll u,ll l,ll r){
	if(l<=tr[u].l&&tr[u].r<=r) return tr[u].sum;
	ll cnt=0;
	ll m=tr[u].l+tr[u].r>>1;
	if(l<=m) cnt^=query(lc,l,r);
	if(m<r) cnt^=query(rc,l,r);
	return cnt;
}
ll dfs(ll u){
	if(d[u]) return d[u];
	for(ll v=u;v<=n;v++){
		if(query(1,u,v)==k){
			if(v==n) d[u]=1;
			else{
				for(ll yy=v+1;yy<=n;yy++){
					d[u]=max(dfs(yy)+1,d[u]);
				}
			}
			break;
		}
	}
	return d[u];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=0&&a[i]!=1) f=false;
		if(a[i]==1) cnt++;
		if(a[i]==0) cntt++;
	}
	if(f){
		if(k==1) printf("%lld",cnt);
		else printf("%lld",cntt+cnt>>1);
		return 0;
	}
	build(1,1,n);
	for(ll i=1;i<=n;i++){
		ans=max(ans,dfs(i));
	}
	printf("%lld",ans);
	return 0;
}
