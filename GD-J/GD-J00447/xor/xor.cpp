#include <bits/stdc++.h>
using namespace std;
#define zqj tre[q].l
#define yqj tre[q].r
#define le q<<1
#define ri q<<1|1
long long n,k;
long long m[500005];
long long da=0;
struct xds{
	long long l,r;
	long long sum;
	void oin(long long ll,long long rr,long long ss){
		l=ll;
		r=rr;
		sum=ss;
	}
}tre[2000005];
void pushup(long long q){
	tre[q].sum=(tre[le].sum^tre[ri].sum);
}
void build(long long q,long long l,long long r){
	tre[q].oin(l,r,m[l]);
	if(l==r) return ;
	long long mid=l+r>>1;
	build(le,l,mid);
	build(ri,mid+1,r);
	pushup(q);
}
long long query(long long q,long long ml,long long mr){
	if(ml<=zqj&&mr>=yqj) return tre[q].sum;
	long long mid=zqj+yqj>>1,ans=0;
	if(ml<=mid) ans^=(query(le,ml,mr));
	if(mr>mid) ans^=(query(ri,ml,mr));
	return ans;
}
struct xds2{
	long long l,r;
	long long sum;
	long long add;
	void oin(long long ll,long long rr,long long ss){
		add=0;
		l=ll;
		r=rr;
		sum=ss;
	}
}tre2[2000005];
void pushup2(long long q){
	tre2[q].sum=max(tre2[le].sum,tre2[ri].sum);
}
void pushdown(long long q){
	if(tre2[q].add==1){
		tre2[le].sum=1;
		tre2[le].add=1;
		tre2[ri].sum=1;
		tre2[ri].add=1;
		tre2[q].add=0;
	}
}
void build2(long long q,long long l,long long r){
	tre2[q].oin(l,r,0);
	if(l==r) return ;
	long long mid=l+r>>1;
	build2(le,l,mid);
	build2(ri,mid+1,r);
	pushup2(q);
}
void chang(long long q,long long ml,long long mr){
	if(ml<=tre2[q].l&&mr>=tre2[q].r){
		tre2[q].sum=1;
		tre2[q].add=1;
		return ;
	}
	pushdown(q);
	long long mid=tre2[q].l+tre2[q].r>>1;
	if(ml<=mid) chang(le,ml,mr);
	if(mr>mid) chang(ri,ml,mr);
	pushup2(q);
}
long long query2(long long q,long long ml,long long mr){
	if(ml<=tre2[q].l&&mr>=tre2[q].r) return tre2[q].sum;
	pushdown(q);
	long long mid=tre2[q].l+tre2[q].r>>1,ans=0;
	if(ml<=mid) ans=max(ans,query2(le,ml,mr));
	if(mr>mid) ans=max(ans,query2(ri,ml,mr));
	return ans;
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; i++) cin>>m[i];
	build(1,1,n);
	build2(1,1,n);
	for(long long i=1;i<=n;i++){
		for(long long j=n;j>=i;j--){
			if(query2(1,j-i+1,j)==1) continue;
			if(query(1,j-i+1,j)==k){
				da++;
				chang(1,j-i+1,j);
			}
		}
	}
	cout<<da;
	return 0;
}
//[60,80]pts 
