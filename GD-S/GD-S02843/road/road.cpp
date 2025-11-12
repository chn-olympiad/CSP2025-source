#include<bits/stdc++.h>
#define ll long long
#define INF 1000000000000000000
using namespace std;
ll n,m,k,u,v,w,usek[15],cstk[15],ans;
ll pk[15][10005];
ll fa[10005];
struct edge{
	ll u,v,w;
}E[2000005],ek[2000005],pe[2000005];
bool cmp(edge x,edge y){
	return x.w < y.w;
}
void res(){
	for(int i=1;i<=n+10;i++)fa[i] = i;
}
ll find(ll x){
	if(fa[x] == x)return x;
	return fa[x] = find(fa[x]);
}
void unionn(ll a,ll b){
	a = find(a);
	b = find(b);
	fa[a] = b;
}
ll solve(){
	ll cnt = 0,pl = 0,tot = 0;
	ll costk = 0,costm = 0;
	for(int i=1;i<=m;i++){
		pe[i] = E[i];
	}
	for(int i=1;i<=k;i++){
		if(usek[i]){
			costk += cstk[i];
			pl++;
			for(int j=1;j<=n;j++){
				ek[cnt+j] = {j,n+i,pk[i][j]};
			}
			cnt+=n;
		}
	}
	res();
	ek[cnt+1] = {INF,INF,INF};
	sort(ek+1,ek+cnt+1,cmp);
	ll pt1 = 1,pt2 = 1;
	for(int i=1;i<=cnt+m;i++){
		if(E[pt1].w < ek[pt2].w){
			pe[i] = E[pt1];
			pt1++;
		}
		else{
			pe[i] = ek[pt2];
			pt2++;
		}
	}
	for(int i=1;i<=cnt+m;i++){
		u = pe[i].u;
		v = pe[i].v;
		w = pe[i].w;
		if(find(u) != find(v)){
			unionn(u,v);
			costm += w;
			tot++;
			if(costk + costm > ans)return INF;
			if(tot >= n+pl-1)break;
		}
	}
	return costk+costm;
}
void dfs(int step,int cost){
	if(cost > ans)return;
	if(step > k){
		ans = min(ans,solve());
		return;
	}
	usek[step] = 0;
	dfs(step+1,cost);
	usek[step] = 1;
	dfs(step+1,cost+cstk[step]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		E[i] = {u,v,w};
	}
	E[m+1] = {INF,INF,INF};
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=k;i++){
		scanf("%lld",&cstk[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&pk[i][j]);
		}
	}
	ans = INF;
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
