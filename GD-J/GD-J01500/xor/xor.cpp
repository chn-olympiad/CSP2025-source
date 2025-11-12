#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,s,maxx;
int a[500005];
struct f{
	int l,r;
}b[1000005];
int cmp(f x,f y){
	if(x.l!=y.l) return x.l<y.l;
	else return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i) scanf("%lld",&a[i]),maxx=max(maxx,a[i]),s+=a[i];
	if(maxx<=1){
		if(k==0){
			int sum=0;
			for(int i=2;i<=n;++i)
				if(a[i]==1&&a[i-1]==1) ++sum,a[i]=0;
			printf("%lld",max(sum,n-s));
		}
		else printf("%lld",s);
		return 0;
	}
	int ans=0;
	s=0;
	for(int cnt=1;cnt<=n;++cnt)
		for(int i=cnt;i<=n;++i){
			int j=i-cnt+1,d=0;
			for(;j<=i;++j) d^=a[j];
			if(d==k) b[++s].l=i-cnt+1,b[s].r=i;
		}
	sort(b+1,b+1+s,cmp);
	for(int i=1;i<=s;++i){
		int sum=1,l=b[i].l,r=b[i].r;
		for(int j=i+1;j<=s;++j)
			if(!(b[j].l<=r&&b[j].l>=l)) ++sum,l=b[j].l,r=b[j].r; 
		ans=max(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
