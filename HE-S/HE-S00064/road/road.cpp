//It's a good problem,thank you ccf.
//may I'll afo.
//but...
//good bye OI.
//we are such a ku ming yuan yang.
//      |
// o / (O)
// |/ /( )\ 
// |  [___]
///\   | |
//ccf qing su su dong shou
//17:58 It's time qwq
//good bye
//thank you see my words
//and... good night.
#include<bits/stdc++.h>
using namespace std;
const int N=1e4+1,M=2e6;
struct edge{int u,v,w;}e[M],b[M];
int n,m,k,c[N],a[11][N];
int p[N];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
int find(int now){
	if(now==p[now])return now;
	return p[now]=find(p[now]);
}
long long kruscal(){
	sort(b+1,b+m+1,cmp);
	long long res=0;
	for(register int i=1;i<=n;++i)p[i]=i;
	for(register int i=1;i<=m;++i){
		int u=b[i].u,v=b[i].v,w=b[i].w;
		int fx=find(u),fy=find(v);
		if(fx!=fy){
//			printf("-----%d %d\n",u,v);
			p[fx]=fy,res+=w;
		}
	}
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(register int i=1;i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	for(register int i=1;i<=k;++i){
		scanf("%d",&c[i]);
		for(register int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	}
	long long ans=1e18;
	for(register int i=0;i<(1<<k);++i){
		int tmp=m;
		long long res=0;
		for(register int j=0;j<k;++j)
			if((i>>j)&1){
				res+=c[j+1]+a[j+1][j+1];
				for(int q=1;q<=n;++q)e[++m]=(edge){j+1,q,a[j+1][q]};
			}
		for(register int j=1;j<=m;++j)b[j]=e[j];
		ans=min(ans,kruscal()+res);
		m=tmp;
	}
	printf("%lld\n",ans);
	return 0;
}
