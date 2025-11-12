#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long LL;
struct Node{
	LL l,r;
}a[N];
LL sum[N],num[N];
LL n,k,tot;
bool cmp(const Node &x,const Node &y){
	return x.r<y.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for(LL i=1;i<=n;++i){
		scanf("%lld",&num[i]);
		sum[i]=num[i]^sum[i-1];
	}
	for(LL i=1;i<=n;++i){
		for(LL j=i;j<=n;++j){
			if((sum[j]^sum[i-1])==k){
				a[++tot].l=i;
				a[tot].r=j;
			}
		}
	}
	sort(a+1,a+1+tot,cmp);
	LL ans=1,R=a[1].r;
	for(LL i=2;i<=tot;++i){
		if(a[i].l>R){
			ans++;
			R=a[i].r;
		}
	}
	printf("%lld",ans);
	return 0;
}
