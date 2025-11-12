#include<bits/stdc++.h>
#define ll long long
#define MAXN 200005
using namespace std;
ll n,Q;
char s[MAXN];
//ll delta[MAXN];
//bool cnt[MAXN/*pos*/][MAXN/*delta*/];
ll delta[MAXN],cnt[MAXN],st[MAXN];
struct bit{
	ll t[MAXN];
	ll b(ll x){
		return x&(-x); 
	}
	void in(ll pos,ll val){
		for(ll i=pos;i<=n;i+=b(i)){
			t[i]=std::max(t[i],val);
		}
	}
	ll val(ll pos){
		ll ans=0;
		for(;pos;pos-=b(pos)){
			ans=std::max(ans,t[pos]);
		}
		return ans;
	}
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&Q);
//	mp.clear();
	while(n--){
		scanf("%s",s+1);
		ll pos=0;
		for(ll i=1;i<=strlen(s+1);++i){
			if(s[i]=='b'){
				pos=i;
				break;
			}
		}
		scanf("%s",s+1);
		for(ll i=1;i<=strlen(s+1);++i){
			if(s[i]=='b'){
//				if(start[i]>pos)
//				start[pos]
				cnt[i-pos]++;
				
				break;
			}
		}
	}
	while(Q--){
		scanf("%s",s+1);
		ll pos=0;
		for(ll i=1;i<=strlen(s+1);++i){
			if(s[i]=='b'){
				pos=i;
				break;
			}
		}
		scanf("%s",s+1);
		for(ll i=1;i<=strlen(s+1);++i){
			if(s[i]=='b'){
				if(delta[i-pos]!=0)std::cout<<delta[i-pos]<<endl;
				break;
			}
		}
	}
	
	return 0;
}
