#include<bits/stdc++.h>
#define ll long long 
#define mk(l,r) make_pair(l,r)
using namespace std;


const ll N=1e5+100;
ll T;
ll n,ans;
ll dp[N],sa[N],sb[N],sc[N];
bool f[N],fa;
struct PERSON{
	ll a,b,c;
}p[N];


bool cmp(PERSON x,PERSON y){
	return x.a>y.a;
}


ll FA(){
	ll ret=0;
	sort(p+1,p+1+n,cmp);
	for(ll i=1;i<=n/2;i++){
		ret=ret+p[i].a;
	}
	return ret;
}


void dg(ll x,ll y,ll A,ll B,ll C){
	if(x==n){
		ans=max(ans,y);
		return;
	}
	for(ll i=1;i<=n;i++){
		if(f[i]==false){
			f[i]=true;
			if(A+1<=n/2){
				dg(x+1,y+p[i].a,A+1,B,C);
			}
			if(B+1<=n/2){
				dg(x+1,y+p[i].b,A,B+1,C);
			}
			if(C+1<=n/2){
				dg(x+1,y+p[i].c,A,B,C+1);
			}
			f[i]=false;
		}
	}
	return;
}


void solve(){
	ans=INT_MIN,fa=true;
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll x,y,z;
		scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
		if(p[i].b!=0||p[i].c!=0){
			fa=false;
		}
		dp[i]=INT_MIN;
	}
	if(fa==true){
		printf("%lld\n",FA());
		return;
	}
	dg(0,0,0,0,0);
	printf("%lld\n",ans);
	return;
}


signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);


	scanf("%lld",&T);
	while(T--){
		solve();
	}
	

	return 0;
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
