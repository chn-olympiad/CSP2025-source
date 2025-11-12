#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+100,M=2e6+5;
int n,m,k,m1;
struct E{
	int u,v,w;
}e1[M],e[M];	
bool cmp(E a,E b){
	return a.w<b.w;
}
int fa[N];
int find(int u){
	if(fa[u]==u) return u;
	else return fa[u]=find(fa[u]);
}
int a[15][N],c[15],fl=1;
int main(){

	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&k);
	for(int i=1;i<=m1;i++){
		scanf("%d%d%d",&e1[i].u,&e1[i].v,&e1[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		if(c[i]) fl=0;
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
//	sort(e1+1,e1+m1+1,cmp);
//	for(int i=1;i<=n+k;i++) fa[i]=i;
//	for(int i=1;i<=m1;i++){
//		int u=e1[i].u;
//		int v=e1[i].v;
//		int fu=find(u),fv=find(v);
//		
//		if(fu==fv) continue;
//		else{
//			fa[fu]=fv;
//			e[++m].u=u,e[m].v=v,e[m].w=e1[i].w;
//		}
//	}
	int mm=0;
	ll ans=1e17,sum=0;
	if(fl){
		mm=m1,sum=0;
		for(int j=1;j<=k;j++){
			for(int q=1;q<=n;q++){
				e1[++mm].u=n+j;
				e1[mm].v=q;
				e1[mm].w=a[j][q];
			}			
		}
		sort(e1+1,e1+mm+1,cmp);
		for(int i=1;i<=n+k;i++) fa[i]=i;
		for(int i=1;i<=mm;i++){
			int u=e1[i].u;
			int v=e1[i].v;
			int fu=find(u),fv=find(v);
			
			if(fu==fv) continue;
			else{
				fa[fu]=fv;
				sum+=e1[i].w;
			}
		}
		ans=min(ans,sum);		
	}
	else{
		for(int i=0;i<(1<<k);i++){
			mm=m1;
			sum=0;
			for(int j=1;j<=k;j++){
				if(i&(1<<j-1)){
					sum+=c[j];
					for(int q=1;q<=n;q++){
						e1[++mm].u=n+j;
						e1[mm].v=q;
						e1[mm].w=a[j][q];
					}				
				}
			}
			sort(e1+1,e1+mm+1,cmp);
			for(int i=1;i<=n+k;i++) fa[i]=i;
			for(int i=1;i<=mm;i++){
				int u=e1[i].u;
				int v=e1[i].v;
				int fu=find(u),fv=find(v);
				
				if(fu==fv) continue;
				else{
					fa[fu]=fv;
					sum+=e1[i].w;
				}
			}
			ans=min(ans,sum);
		}		
	}
	printf("%lld",ans);
	return 0;
}

