#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll result=1;
vector<ll> a(n+5,0);
void pd(vector<ll> b){
	ll max_result=0;
	ll cnt=0;
	for(int i=0;i<b.size();i++){
		max_result=max(max_result,a[b[i]]);
		cnt+=a[b[i]];
	}
	if(cnt>2*max_result) result++;
	
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	if(n==3){
		ll cnt=0,max_cnt=-1;
		for(ll i=1;i<=n;i++){cnt+=a[i];max_cnt=max(max_cnt,a[i]);}
		if(cnt>2*max_cnt) printf("%lld",1);
		else printf("%lld",0);
		return 0;
	}
//	else{
//		for(ll i=1;i<=n-3;i++){
//			ll max_result=max(a[i],max(a[i+1],a[i+2]));
//			ll cnt=a[i]+a[i+1]+a[i+2];
//			if(cnt>2*max_result) result++;
//			pd({i,i+1,i+2,i+3});
//		}
//	}
	for(int i=1;i<=n;i++){
		result*=i;
	}
	printf("%lld",result%998%244%353);
	return 0;
}
