#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10010],maxn,w[15],c[12][10010],cnt,ans;
struct node{
	long long u,v,w;
}e[1001000];
bool cmp(node a,node b){
	return a.w<b.w;
}
long long f(long long x){
	if (x==fa[x])return x;
	return fa[x]=f(fa[x]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for (int i=1;i<=n;i++)fa[i]=i;
	for (int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for (int i=1;i<=k;i++){
		scanf("%lld",&w[i]);
		maxn=max(maxn,w[i]);
		for (int j=1;j<=n;j++){
			scanf("%lld",&c[i][j]);
		}
	}
	if (k==0){
	    sort(e+1,e+1+m,cmp);
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++){
				int fx=f(i),fy=f(j);
				if (fx!=fy){
					fa[fx]=fy;
					cnt++;
				}
			}
		}
		for (int i=1;i<=m&&cnt<n-1;i++){
			int fx=f(e[i].u),fy=f(e[i].v);
			if (fx!=fy){
				fa[fx]=fy;
				cnt++;
				ans+=e[i].w;
			}
		}
		printf("%lld",ans);
	}else if (maxn==0){
		for (int i=1;i<=k;i++){
			for (int j=1;j<=n;j++){
				for (int t=j+1;t<=n;t++){
					e[++m].u=j;
					e[m].v=t;
					e[m].w=c[i][j]+c[i][t];
				}	
			}
		}
		sort(e+1,e+1+m,cmp);
		for (int i=1;i<=m&&cnt<n-1;i++){
			long long fx=f(e[i].u),fy=f(e[i].v);
			if (fx!=fy){
				fa[fx]=fy;
				cnt++;
				ans+=e[i].w;
			}
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
