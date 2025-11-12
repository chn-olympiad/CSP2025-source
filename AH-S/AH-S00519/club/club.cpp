#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct area{
	ll a,b,c;
}w[100010];
bool cmp(const area &x,const area &y){
		if(x.a!=y.a){
			return x.a>y.a;
		}
		else if(x.b!=y.b){
			return x.b>y.b;
		}
		else return x.c>y.c;
}
int main (){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll T;
	scanf("%lld",&T);
	while(T--){
		ll n;
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			scanf("%lld%lld%lld",&w[i].a,&w[i].b,&w[i].c);
		}
		sort(w+1,w+n+1,cmp);
		ll aa=n/2,bb=n/2,cc=n/2;
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ll maxn=-1;
			maxn=max(w[i].a,max(w[i].b,w[i].c)); 
			
			
			if(maxn==w[i].a){
				if(aa>0){
					aa--;
					ans+=w[i].a;
				}
				else{
					maxn=max(w[i].b,w[i].c);
					if(maxn==w[i].b){
						bb--;
						ans+=w[i].b;
					}
					else{
						cc--;
						ans+=w[i].c;
					}
				}
			}
			
			
			
			
			if(maxn==w[i].b){
				if(bb>0){
					bb--;
					ans+=w[i].b;
				}
				else{
					maxn=max(w[i].a,w[i].c);
					if(maxn==w[i].a){
						aa--;
						ans+=w[i].a;
					}
					else{
						cc--;
						ans+=w[i].c;
					}
				}
			}
			
			
			
			if(maxn==w[i].c){
				if(cc>0){
					cc--;
					ans+=w[i].c;
				}
				else{
					maxn=max(w[i].b,w[i].a);
					if(maxn==w[i].a){
						aa--;
						ans+=w[i].a;
					}
					else{
						bb--;
						ans+=w[i].b;
					}
				}
			}
			
			
		}
		printf("%lld\n",ans);
	}
	return 0;
}
