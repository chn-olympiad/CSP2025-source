#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=100010 ;
ll min(ll x,ll y) {
	return x<y?x:y ;
}
ll max(ll x,ll y) {
	return x>y?x:y ;
}
ll a[N][4] ;
ll ans,cnt,n;
vector<ll> st[4] ;
ll que[N] ;
ll cnt1,cnt2,cnt3;
void fil() {
	freopen("club.in","r",stdin) ;
	freopen("club.out","w",stdout) ;
} 
void solve() {
	scanf("%lld",&n) ;
	for(int i=1;i<=n;i++) {
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]) ;
	}
	ans=0;cnt1=0;cnt2=0;cnt3=0;
	for(int i=1;i<=n;i++) {
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]) {
			st[1].push_back(i) ;ans+=a[i][1];cnt1++ ;
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]) {
			st[2].push_back(i) ;ans+=a[i][2];cnt2++;
		}
		else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]) {
			st[3].push_back(i) ;ans+=a[i][3] ;cnt3++;
		}
	}
	cnt=0;
	if(cnt1>n/2) {
		ll tim=cnt1-n/2 ;
		for(ll u:st[1]) {
			ll tmp=min(a[u][1]-a[u][2],a[u][1]-a[u][3]) ;
			que[++cnt]=tmp ;
		}
		sort(que+1,que+cnt+1) ;
		for(int i=1;i<=tim;i++) {
			ans-=que[i] ;
		}
	}
	else if(cnt2>n/2) {
		ll tim=cnt2-n/2 ;
		for(ll u:st[2]) {
			ll tmp=min(a[u][2]-a[u][1],a[u][2]-a[u][3]) ;
			que[++cnt]=tmp ;
//			printf("		%lld\n",tmp) ;
		}
		sort(que+1,que+cnt+1) ;
		for(int i=1;i<=tim;i++) {
			ans-=que[i] ;
		}
	}
	else if(cnt3>n/2) {
		ll tim=cnt3-n/2 ;
		for(ll u:st[3]) {
			ll tmp=min(a[u][3]-a[u][2],a[u][3]-a[u][1]) ;
			que[++cnt]=tmp ;
		}
		sort(que+1,que+cnt+1) ;
		for(int i=1;i<=tim;i++) {
			ans-=que[i] ;
		}
	}
	st[1].clear();st[2].clear();st[3].clear() ;
	printf("%lld\n",ans) ;
}
ll T ;
int main() {
	fil() ;
	scanf("%lld",&T) ;
	while(T--) solve() ;
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
