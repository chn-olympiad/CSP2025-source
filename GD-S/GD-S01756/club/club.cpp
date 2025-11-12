#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll mid(ll a,ll b,ll c){
	if((a>=b&&b>=c)||(c>=b&&b>=a)) return b;
	if((b>=a&&a>=c)||(c>=a&&a>=b)) return a;
	if((a>=c&&c>=b)||(b>=c&&c>=a)) return c; 
	return 1e12;
}
struct st{
	ll a,b,c,maxn,minn,midn,maxi,mini,midi;
	bool operator<(const st&_)const{
		if((max({a,b,c})-mid(a,b,c))==(max({_.a,_.b,_.c})-mid(_.a,_.b,_.c)))
			return max({a,b,c})>max({_.a,_.b,_.c});
		return (max({a,b,c})-mid(a,b,c))>(max({_.a,_.b,_.c})-mid(_.a,_.b,_.c));
	}
}a[N];
ll T,n,cnt[10],ans;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		memset(cnt,0,sizeof cnt);
		ans=0ll;
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a,&a[i].b,&a[i].c);
			a[i].maxn=max({a[i].a,a[i].b,a[i].c});
			a[i].minn=min({a[i].a,a[i].b,a[i].c});
			a[i].midn=mid(a[i].a,a[i].b,a[i].c);
			if(a[i].a==a[i].maxn)
				a[i].maxi=1;
			if(a[i].b==a[i].maxn)
				a[i].maxi=2;
			if(a[i].c==a[i].maxn)
				a[i].maxi=3;
			if(a[i].a==a[i].minn)
				a[i].mini=1;
			if(a[i].b==a[i].minn)
				a[i].mini=2;
			if(a[i].c==a[i].minn)
				a[i].mini=3;
			if(a[i].a==a[i].midn)
				a[i].midi=1;
			if(a[i].b==a[i].midn)
				a[i].midi=2;
			if(a[i].c==a[i].midn)
				a[i].midi=3;
		}sort(a+1,a+1+n);
		for(ll i=1;i<=n;i++){
			if(cnt[a[i].maxi]<n/2){
				cnt[a[i].maxi]++;
				ans+=a[i].maxn;
			}else{
				if(cnt[a[i].midi]<n/2){
					cnt[a[i].midi]++;
					ans+=a[i].midn;
				}else{
					cnt[a[i].mini]++;
					ans+=a[i].minn;
				}
					
			}
		}printf("%lld\n",ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

