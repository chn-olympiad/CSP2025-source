#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+15,M=1e7+5;
int n,m,k,fa[N],v[11],cnt,f;
ll ans,ans1;
struct gra{
	int x,y,c;
	ll w;
}g[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
bool cmp(gra x,gra y){
	return x.w<y.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d%d%lld",&g[i].x,&g[i].y,&g[i].w);
	for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0){
		sort(g+1,g+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=find(g[i].x),y=find(g[i].y);
			if(x!=y){
				fa[x]=y;
				cnt++;
				ans+=g[i].w;
				if(cnt==n) break;
			}
		}
		ans1=ans;
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&g[n+i].c);
		for(int j=1;j<=n;j++){
			g[n+i].x=n+i;
			g[n+i].y=j;
			scanf("%lld",&g[n+i].w);
			if(g[n+i].c!=0||g[n+i].w!=0) f=1;
		}
	}
	if(!f){
		sort(g+1,g+1+m,cmp);
		for(int i=1;i<=m-k;i++) ans+=g[i].w;
		printf("%lld",ans);
		return 0;
	}
	printf("%lld",ans1);
	return 0;
} 
