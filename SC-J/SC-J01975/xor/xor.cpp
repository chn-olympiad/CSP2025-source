# include<bits/stdc++.h>
# define int long long
using namespace std;
const int N=5e5+5;
int n,k,a[N];
struct node{
	int l,r,sum;
	bool tab;
}tr[N*4];
void pushup(int p){
	tr[p].sum=tr[p<<1].sum^tr[p<<1|1].sum;
}
void build(int p,int l,int r){
	tr[p]={l,r,a[l],0};
	if(l==r) return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	pushup(p);
}
int ans=0;
void dfs1(int p,int p1){
//	printf("%lld %lld %lld\n",tr[p].l,tr[p].r,tr[p].sum);
	if(tr[p1].tab) return;
	if(tr[p].l==tr[p].r) return;
	if(tr[p].l!=tr[p].r){
		dfs1(p<<1,p1);
		dfs1(p<<1|1,p1);
		tr[p].tab=(tr[p<<1].tab||tr[p<<1|1].tab);
	}
	if(tr[p].tab) return;
	if(tr[p1].l!=1&&(tr[p1].sum^tr[(p<<1)-1].sum)==k&&!tr[(p<<1)-1].tab){
		tr[(p<<1)-1].tab=1;
		tr[p1].tab=1;
		ans++;
		return;
	}
	if(tr[p1].r!=n&&(tr[p1].sum^tr[(p<<1|1)+1].sum)==k&&!tr[(p<<1|1)+1].tab){
		tr[(p<<1|1)+1].tab=1;
		tr[p1].tab=1;
		ans++;
		return;
	}
}
void dfs2(int p){
	if(tr[p].l!=tr[p].r){
		dfs2(p<<1);
		dfs2(p<<1|1);
		tr[p].tab=(tr[p<<1].tab||tr[p<<1|1].tab);
	}
	if(tr[p].tab) return;
	if(tr[p].sum==k){
		ans++;
		tr[p].tab=1;
		return;
	}
	if(tr[p].l!=tr[p].r) dfs1(p,p);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	build(1,1,n);
	dfs2(1);
	printf("%lld",ans);
	return 0;
}