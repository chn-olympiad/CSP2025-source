#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,k,ans,g;
ll X,Y,Z,minn=2e9;
ll f[10015];
ll c[15][10015];
ll sum[2005][15];
ll d[2005];
ll e[10015];
struct node{
	ll u,v,w;
};
bool operator<(node A,node B){
	return A.w>B.w;
}
priority_queue<node> s,t;
ll find(ll x){
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
void dfs(ll x){
	if(x>k){
		ans++;
		for(ll i=1;i<=k;i++){
			sum[ans][i]=d[i];
		}
		return;
	}
	d[x]=0;
	dfs(x+1);
	d[x]=1;
	dfs(x+1);
	return;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		f[i]=i;
		e[i]=1e18;
	}
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&X,&Y,&Z);
		s.push({X,Y,Z});
		e[X]=min(e[X],Z);
		e[X]=min(e[X],Z);
	}
	for(ll i=1;i<=k;i++){
		for(ll j=0;j<=n;j++){
			scanf("%lld",&c[i][j]);
			if(c[i][j]!=0) g=1;
		}
	}
	if(g==0){
		printf("0");
		return 0; 
	}
	dfs(1);
	for(ll i=1;i<=ans;i++){
		t=s;
		ll cnt=0,summ=n,T=m;
		for(ll j=1;j<=k;j++){
			if(sum[i][j]==1){
				cnt+=c[j][0],summ++;
				if(cnt>minn) break;
				for(ll l=1;l<=n;l++){
					if(c[j][l]>e[l]) continue;
					t.push({summ,l,c[j][l]});
					T++;
				}
			}
		}
		if(cnt>minn) continue;
		for(ll i=1;i<=summ;i++){
			f[i]=i;
		}
		for(ll i=1;i<=T;i++){
			node H=t.top();
			t.pop();
			ll U=find(H.u),V=find(H.v);
			if(U!=V){
				f[U]=V;
				cnt+=H.w;
				if(cnt>minn) break;
			}
		}
		minn=min(minn,cnt);
	}
	printf("%lld",minn);
	return 0;
}
