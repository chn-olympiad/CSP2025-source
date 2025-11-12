#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
ll t;
ll n;
struct menber{
	ll x1,x2,x3;
}a[N];
ll ans=-0x3F3F3F3F;
void dfs(ll c1,ll c2,ll c3,ll cnt1,ll cnt2,ll cnt3,ll now){
	if(cnt1>(n/2)||cnt2>(n/2)||cnt3>(n/2)){
		return ;
	}
	if(now>n){
		ans=max(ans,(c1+c2+c3));
		return ;
	}
	dfs(a[now].x1+c1,c2,c3,cnt1+1,cnt2,cnt3,now+1);
	dfs(c1,a[now].x2+c2,c3,cnt1,cnt2+1,cnt3,now+1);
	dfs(c1,c2,a[now].x3+c3,cnt1,cnt2,cnt3+1,now+1);
}
bool cmp(menber aa,menber bb){
	return aa.x1>bb.x2;
}
void dfs2(ll c1,ll c2,ll cnt1,ll cnt2,ll now){
	if(cnt1>(n/2)||cnt2>(n/2)){
		return ;
	}
	if(now>n){
		ans=max(ans,(c1+c2));
		return ;
	}
	dfs2(a[now].x1+c1,c2,cnt1+1,cnt2,now+1);
	dfs2(c1,a[now].x2+c2,cnt1,cnt2+1,now+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	
	while(t--){
		ll flag=0;
		ll flag2=0;
		ans=-0x3F3F3F;
		std::cin>>n;
		for(ll i=1;i<=n;i++){
			std::cin>>a[i].x1>>a[i].x2>>a[i].x3;
			if(a[i].x3!=0||a[i].x2!=0) flag=1;
			if(a[i].x2!=0) flag2=1;
		}
		if(flag==0){
			sort(a+1,a+n+1,cmp);
			ll ans=0;
			for(ll i=1;i<=(n/2);i++){
				ans+=a[i].x1;
			}
			cout<<ans<<'\n';
			continue;
		}
		if(flag2==0){
			dfs2(0,0,0,0,1);
			std::cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,0,0,0,1);
		std::cout<<ans<<'\n';
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

1 3 1 2
4+4+5+5
*/
