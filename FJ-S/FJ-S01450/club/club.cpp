#include<bits/stdc++.h>
#define ll long long
#define db double
#define vec vector
#define pb push_back
#define pll pair<ll,ll>
#define mkp make_pair
#define il inline
#define endl "\n"
const ll mod=998244353;
const ll inf=1e18;
using namespace std;
ll n,ans=0;bool f1=1,f2=1;
struct dat{
	ll a,b,c;
	void rd(){cin>>a>>b>>c;f1&=(b==0&&c==0),f2&=(c==0);}
}dt[200005];
bool cmp1(dat x,dat y){
	return x.a>y.a;
}
bool cmp2(dat x,dat y){
	return x.b>y.b;
} 
bool cmp3(dat x,dat y){
	return x.c>y.c;
}
bool cmp4(dat x,dat y){
	return x.a-y.b>y.a-y.b;
}
bool cmp5(dat x,dat y){
	return x.b-x.a>y.b-y.a;
}
bool cmp6(dat x,dat y){
	return max(x.a,x.b)>max(y.a,y.b);
}
void dfs(ll k,ll a,ll b,vec<ll> jca,vec<ll> jcb){
	if(a>(n>>1)||b>(n>>1)) return ;
	if(k==n){
		if(a>(n>>1)||b>(n>>1)) return ;
		vec<ll> vis(n+1,0);
		ll c=n-a-b;
		if(c>(n>>1)) return ;
		ll res=0;
		for(ll rp:jca) vis[rp]=1,res+=dt[rp].a;
		for(ll rp:jcb) vis[rp]=1,res+=dt[rp].b;
		for(ll i=1;i<=n;i++){
			if(!vis[i]) res+=dt[i].c;
 		} 
 		ans=max(ans,res);
// 		cout<<res<<" ";
 		return ;
	}
	dfs(k+1,a,b,jca,jcb);
	jca.pb(k+1),dfs(k+1,a+1,b,jca,jcb);
	jca.pop_back(),jcb.pb(k+1),dfs(k+1,a,b+1,jca,jcb);
	jcb.pop_back(); 
} 
void solve(){
	cin>>n;f1=f2=1;
	for(ll i=1;i<=n;i++) dt[i].rd();
	if(f1){
		ll res=0;
		sort(dt+1,dt+n+1,cmp1);
		for(ll i=1;i<=(n>>1);i++) res+=dt[i].a;
		cout<<res<<endl;
	}else if(f2){
		ll ans1=0,ans2=0,ans3=0,ans4=0;
		sort(dt+1,dt+n+1,cmp1);
		for(ll i=1;i<=(n>>1);i++) ans1+=dt[i].a;
		for(ll i=(n>>1)+1;i<=n;i++) ans1+=dt[i].b;
		sort(dt+1,dt+n+1,cmp2);
		for(ll i=1;i<=(n>>1);i++) ans2+=dt[i].b;
		for(ll i=(n>>1)+1;i<=n;i++) ans2+=dt[i].a;
		sort(dt+1,dt+n+1,cmp4);
		for(ll i=1;i<=(n>>1);i++) ans3+=dt[i].a;
		for(ll i=(n>>1)+1;i<=n;i++) ans3+=dt[i].b;
		sort(dt+1,dt+n+1,cmp5);
		for(ll i=1;i<=(n>>1);i++) ans4+=dt[i].b; 
		for(ll i=(n>>1)+1;i<=n;i++) ans4+=dt[i].a;
		cout<<max(ans1,max(ans2,max(ans3,ans4)))<<endl;
	}else if(n<=30){
		vec<ll> ra,rb;ans=0;
		dfs(0,0,0,ra,rb);
		cout<<ans<<endl;
	}else{
		ll ans=0;
		sort(dt+1,dt+n+1,cmp1);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i>(n>>1)||j>(n>>1)) continue; 
				if((n-i-j)>(n>>1)) continue;
				ll rp=0;
				for(ll k=1;k<=i;k++) rp+=dt[i].a;
				for(ll k=i+1;k<=i+j;k++) rp+=dt[i].b;
				for(ll k=(n-i-j)+1;k<=n;k++) rp+=dt[i].c;
				ans=max(ans,rp);
			} 
		} 
		sort(dt+1,dt+n+1,cmp2);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i>(n>>1)||j>(n>>1)) continue; 
				if((n-i-j)>(n>>1)) continue;
				ll rp=0;
				for(ll k=1;k<=i;k++) rp+=dt[i].b;
				for(ll k=i+1;k<=i+j;k++) rp+=dt[i].a;
				for(ll k=(n-i-j)+1;k<=n;k++) rp+=dt[i].c;
				ans=max(ans,rp);
			} 
		} 
		sort(dt+1,dt+n+1,cmp3);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=n;j++){
				if(i>(n>>1)||j>(n>>1)) continue; 
				if((n-i-j)>(n>>1)) continue;
				ll rp=0;
				for(ll k=1;k<=i;k++) rp+=dt[i].c;
				for(ll k=i+1;k<=i+j;k++) rp+=dt[i].a;
				for(ll k=(n-i-j)+1;k<=n;k++) rp+=dt[i].b;
				ans=max(ans,rp);
			} 
		} 
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	ll T;cin>>T;
	while(T--) solve();
	return 0;
}
/* 
*/

