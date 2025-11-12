#include <bits/stdc++.h>
using namespace std;
struct ha{
	int x,r;
	inline bool operator < (const ha &o) const{
		if(x!=o.x) return x<o.x;
		return r<o.r;
	}
};
set<ha> s;
int n,k,a[500005],sum[500005],cnt,ans,r;
struct haa{
	int l,r;
	inline bool operator < (const haa &o) const{
		if(r!=o.r) return r<o.r;
		return l<o.l;
	}
};
haa b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
		s.insert(ha{sum[i],i});
	}
	for(int i=1;i<=n;i++){
		auto p=s.lower_bound(ha{k,i});
		if(p!=s.end()&&p->x==k) b[++cnt]=haa{i,p->r};
		k^=a[i];
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++) if(b[i].l>r){
		r=b[i].r;
		ans++;
	}
	printf("%d",ans);
	return 0;
}
