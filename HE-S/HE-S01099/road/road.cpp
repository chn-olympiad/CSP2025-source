#include<bits/stdc++.h>
using namespace std;
const long long MX=2001000,INF=0x3f3f3f3f;
struct node{
	long long x,y,w;
}edge[MX];
mt19937 rnd(11211121);
inline bool cmp(node a,node b){
	return a.w<b.w;
}
long long fath[MX];
long long fnd(long long x){
	if(x==fath[x])  return x;
	return fath[x]=fnd(fath[x]);
}
long long a[MX];
void solve(){
	long long n,m,k;scanf("%lld%lld%lld",&n,&m,&k);
	for(long long i=1;i<=n;i++)  fath[i]=i;
	for(long long i=1;i<=m;i++)  scanf("%lld%lld%lld",&edge[i].x,&edge[i].y,&edge[i].w);
	for(long long i=1;i<=k;i++){
		long long x,pos=0;scanf("%lld",&x);
		for(long long j=1;j<=n;j++){
			scanf("%lld",&a[j]);
			if(a[j]==0)  pos=j;
		}
		for(long long j=1;j<=n;j++){
			if(j==pos)  continue;
			edge[++m].x=pos,edge[m].y=j,edge[m].w=a[j];
		}
	}
	sort(edge+1,edge+1+m,cmp);
	long long sum=0,ans=0;
	for(long long i=1;i<=m;i++){
		long long fx=fnd(edge[i].x),fy=fnd(edge[i].y);
		if(fx==fy)  continue;
		if(rnd()&1)  swap(fx,fy);
		fath[fx]=fy;
		sum++,ans+=edge[i].w;
	}
	printf("%lld",ans);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long T=1;
	while(T--)  solve();
	return 0;
}
