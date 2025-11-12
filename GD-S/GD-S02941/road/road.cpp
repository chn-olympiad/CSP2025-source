#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
ll MIN(ll x,ll y){return x<y?x:y;}
const int N=5e6+8;
const ll inf=1e18;
int n,m,k,f[N];
ll c[N],a[18][N];
ll ans;
struct edge{
	int u,v;
	ll w;
}G[N],e[N];
int find(int x){
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&G[i].u,&G[i].v,&G[i].w);
		e[i]=G[i];
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++) f[i]=i;
	sort(e+1,e+m+1,cmp);
	int cnt=0;
	for(int i=1;i<=m;i++){
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		ans+=e[i].w;
		f[fu]=fv;
		if(cnt==n-1) break;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m;j++) e[j]=G[j];
		for(int j=1;j<=n;j++){
			e[j+m]={n+1,j,a[i][j]};
		}
		for(int j=1;j<=n+1;j++) f[j]=j; 
		sort(e+1,e+m+n+1,cmp);
		ll answer=0;
		cnt=0;
		for(int j=1;j<=m+n;j++){
			int fu=find(e[j].u),fv=find(e[j].v);
			if(fu==fv) continue;
			answer+=e[j].w;
			f[fu]=fv;
			cnt++;
			if(cnt==n) break;
		}
//		printf("%lld\n",answer);
		if(answer+c[i]<ans){
			ans=answer+c[i];
			m+=n;
			n++;
		}
	}
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
