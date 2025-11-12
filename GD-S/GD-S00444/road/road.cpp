#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+1,M=1e6+1;
int n,m,k,f[N];
ll val[11][N],c[N],ans=1e18;
struct e{
	int u,v;
	ll w;
}a[M];
bool cmp(e a,e b){
	return a.w<b.w;
}
int getf(int x){
	int v=x,tmp;
	while(v!=f[v])v=f[v];
	while(x!=v){
		tmp=f[x],f[x]=v,x=tmp;
	}
	return v;
}
ll solve(int s){
	ll res=0;
	int len=0,p1=1,p2=1;
	e b[100001];
	for(int i=0;i<k;i++){
		if(s&(1<<i)){
			res+=c[i];
			for(int j=1;j<=n;j++)b[++len]={j,n+i+1,val[i][j]};
		}
	}
	for(int i=1;i<=n+k;i++)f[i]=i;
	sort(b+1,b+1+len,cmp);
	while(p1<=m||p2<=len){
		e now;
		if((p2>len||a[p1].w<b[p2].w)&&p1<=m)
			now=a[p1++];
		else now=b[p2++];
		int fx=getf(now.u),fy=getf(now.v);
		if(fx!=fy)res+=now.w,f[fx]=fy;
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&a[i].u,&a[i].v,&a[i].w);
	}
	sort(a+1,a+1+m,cmp);
	for(int i=0;i<k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%lld",&val[i][j]);
	}
	for(int s=0;s<(1<<k);s++){
		ans=min(ans,solve(s));
	}
	printf("%lld",ans);
	return 0;
}
