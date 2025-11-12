#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M = 1e6 + 7;
const ll oo = 1e16 + 7;
ll w, ans;
struct edge{int x, y; ll w;}edt[M], edo[M], ed[M]; int edn, edtn;
bool cmp(edge e1, edge e2){return e1.w<e2.w;}
int n, m, i, j, k, x, y, st, f[M];
int z(int x){return x==f[x]?x:f[x]=z(f[x]);}
ll c[M], a[12][M/10];

ll mstt(ll st){
	ll ans=0;
	for(edtn=n-1,i=1;i<n;i++) edt[i]=ed[i];
	for(i=1;i<=k;i++)if((st>>i-1)&1)for(j=1;j<=n;j++){
		edt[++edtn]={n+i, j, a[i][j]};
	}
	sort(edt+1, edt+edtn+1, cmp);
	for(i=1;i<=n+k;i++)f[i]=i;
	for(i=1;i<=edtn;i++){
		x=z(edt[i].x);
		y=z(edt[i].y);
		if(x!=y) f[x]=y, ans+=edt[i].w;
	}
	for(i=1;i<=k;i++) ans+=((st>>i-1)&1)*c[i];
	return ans;
}

ll QuetionAns(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++) f[i]=i;
	for(i=1;i<=m;i++) {
		scanf("%d%d%lld",&x,&y,&w);
		edo[i]={x, y, w};
	}
	sort(edo+1, edo+m+1, cmp);
	for(i=1;i<=m;i++){
		x=z(edo[i].x);
		y=z(edo[i].y);
		if(x!=y) f[x]=y, ed[++edn]=edo[i];
	}
	for(i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	if(k<=5){
		for(ans=oo,st=0;st<(1<<k);st++)ans=min(ans, mstt(st)); return ans;
	}
	return mstt((1<<k)-1);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	printf("%lld",QuetionAns()); return 0;
}
