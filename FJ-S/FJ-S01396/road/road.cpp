#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k,fa[10005],ans = LLONG_MAX,vis[15],tot,a[15][10005],c[15];
struct Node{
	ll u,v,w;
}edge[1100005],tmp[1100005];
bool cmp(Node node1,Node node2){
	return node1.w < node2.w;
}
ll find(ll x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void dfs(ll now,ll ret){
	if(now > k){
		for(ll i = 1;i <= m;i++)tmp[i] = edge[i];
		for(ll i = 1;i <= tot;i++)fa[i] = i;
		sort(tmp + 1,tmp + m + 1,cmp);
		ll otp = ret,cnt = 0;
		for(ll i = 1;i <= m;i++){
			if(cnt == tot - 1)break;
			ll tmpu = find(tmp[i].u),tmpv = find(tmp[i].v);
			if(tmpu == tmpv)continue;
			otp += tmp[i].w,cnt++,fa[tmpu] = tmpv;
		}
		ans = min(ans,otp);
		return ;
	}
	vis[now] = 0;
	dfs(now + 1,ret);
	vis[now] = 1,tot++;
	for(ll i = 1;i <= n;i++)edge[++m] = (Node){i,tot,a[now][i]};
	dfs(now + 1,ret + c[now]);
	vis[now] = 0,tot--,m -= n;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	tot = n;
	for(ll i = 1;i <= n;i++)fa[i] = i;
	for(ll i = 1;i <= m;i++)scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	for(ll i = 1;i <= k;i++){
		scanf("%lld",&c[i]);
		for(ll j = 1;j <= n;j++)scanf("%lld",&a[i][j]);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
