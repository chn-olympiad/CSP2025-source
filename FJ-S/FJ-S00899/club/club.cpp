#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll t,n,maxn,f1;
ll a[100005][5];
priority_queue<ll> q;
void clear(){
	priority_queue<ll> p;
	swap(q,p);
	return;
}
void dfs(ll x,ll b,ll c,ll d,ll sum){
	if(b*2>n) return;
	if(c*2>n) return;
	if(d*2>n) return;
	if(x>n){
		maxn=max(maxn,sum);
		return;
	}
	dfs(x+1,b+1,c,d,sum+a[x][1]);
	dfs(x+1,b,c+1,d,sum+a[x][2]);
	dfs(x+1,b,c,d+1,sum+a[x][3]);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&t);
	while(t--){
		maxn=0;
		clear();
		scanf("%lld",&n);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				scanf("%lld",&a[i][j]);
			}
			if(a[i][3]!=0) f1=1;
		}
		if(f1==0){
			for(ll i=1;i<=n;i++){
				q.push(a[i][1]);
			}
			ll ans=0,cnt=0;
			while(cnt*2<n){
				ans+=q.top();
				cnt++;
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(1,0,0,0,0);
		printf("%lld\n",maxn);
	}
	return 0;
}
