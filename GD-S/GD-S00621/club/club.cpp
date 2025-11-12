#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N=1e5+20;
ll t,n,ans,cnt[5];
struct Node{
	ll x,bel,y;
}g[N];

void solve(){
	priority_queue<ll>q[5];
	scanf("%lld",&n);ans=cnt[1]=cnt[2]=cnt[3]=0;
	for(ll i=1,a,b,c;i<=n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		g[i].x=max(max(a,b),c);
		if(a==g[i].x)g[i].y=max(b,c)-g[i].x,g[i].bel=1;
		else if(b==g[i].x)g[i].y=max(a,c)-g[i].x,g[i].bel=2;
		else g[i].y=max(a,b)-g[i].x,g[i].bel=3;
//		printf("%lld %lld\n",g[i].x,g[i].y);
	}
	for(ll i=1;i<=n;i++){
		ll b=g[i].bel;
		if(cnt[b]==n/2){
			ll tp=q[b].top();
			if(g[i].y>=tp)ans+=(g[i].x+g[i].y);
			else{
				ans+=(g[i].x+tp);
				q[b].pop();q[b].push(g[i].y);
			}
		}
		else{
			ans+=g[i].x,cnt[b]++;
			q[b].push(g[i].y);
		}
	}
	
	printf("%lld\n",ans);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--)solve();
	return 0;
} 
