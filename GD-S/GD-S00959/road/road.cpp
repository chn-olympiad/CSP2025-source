#include<bits/stdc++.h>
#define ll long long
#define N 10005
#define M 1000005
#define lg 25 
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
ll n,m,h,ek,k,a[15][N],p[N],tot,sum;
struct node{
	ll x,y,w;
}e[M];
vector <node> v[N];
bool cmp(node a,node b){
	return a.w<b.w;
}
ll find(ll x){return x==p[x]?x:p[x]=find(p[x]);}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=m;i++){
		ll x,y,w;scanf("%lld%lld%lld",&x,&y,&w);
		e[i].x=x,e[i].y=y,e[i].w=w;
	}
	for(int i=1;i<=k;i++) for(int j=0;j<=n;j++) scanf("%lld",&a[i][j]);
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++){
		ll x=find(e[i].x),y=find(e[i].y);
		if(x==y) continue;
		p[x]=y;find(x);
		v[e[i].x].push_back({e[i].y,e[i].w});
		v[e[i].y].push_back({e[i].x,e[i].w});
		ek++;sum+=e[i].w;
		if(ek==n-1) break;
	}
	printf("%lld",sum);
	return 0;
}
