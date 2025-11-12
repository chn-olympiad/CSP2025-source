#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
struct per{
	ll w[5];
	ll else_max;
	ll max_num;
	bool f;
};
bool cmp(per a1,per b1){
	if (a1.f) return 0;
	if (b1.f) return 1;
	return (a1.w[1]+b1.else_max) > (b1.w[1]+a1.else_max);
}
int _max(ll a,ll b,ll c){
	if(max(a,max(b,c))==a){
		return 1;
	}
	if(max(a,max(b,c))==b){
		return 2;
	}
	if(max(a,max(b,c))==c){
		return 3;
	}
	return 0;
}
per a[N];
ll cnt[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		int pn=n/2;
		ll ans=0;
		for (int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].w[1],&a[i].w[2],&a[i].w[3]);
			a[i].max_num=_max(a[i].w[1],a[i].w[2],a[i].w[3]);
			cnt[a[i].max_num]++;
			ans+=max(a[i].w[1],max(a[i].w[2],a[i].w[3]));
		}
		ll most=max(cnt[1],max(cnt[2],cnt[3]));
		int wh_most=_max(cnt[1],cnt[2],cnt[3]);
		if(most<=pn){
			printf("%lld\n",ans);
			continue;
		}
		for (int i=1;i<=n;i++){
			if (a[i].max_num!=wh_most){
				a[i].f=1;
				a[i].else_max=0;
			} 
			else{
				a[i].f=0;
				swap(a[i].w[1],a[i].w[a[i].max_num]);
				a[i].else_max=max(a[i].w[2],a[i].w[3]);
			}
		}
		sort(a+1,a+1+n,cmp);
		ans=0;
		for (int i=1;i<=pn;i++){
			ans+=a[i].w[1];
		}
		for (int i=pn+1;i<=n;i++){
			if (a[i].f) ans+=max(a[i].w[1],max(a[i].w[2],a[i].w[3]));
			else ans+=a[i].else_max;
		}
		printf("%lld\n",ans);
	}
	return 0;
} 

