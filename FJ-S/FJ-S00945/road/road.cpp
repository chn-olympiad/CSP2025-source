#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
#define N 10005
using namespace std;
int n,m,k,c[15],a[15][N],f[N];
bool vis[N];
struct code{
	int u,v,w;
}e[1100005];
bool cmp(code x,code y){
	return x.w<y.w;
}
int find(int x){
	return x==f[x]?x:f[x]=find(f[x]);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			f[i]=i;
		}
		sort(e+1,e+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy){
				f[fx]=fy;
				ans+=e[i].w;
				++cnt;
			}
			if(cnt==n-1){
				printf("%lld",ans);
				break;
			}
		}
	}else{
		for(int i=1;i<=n+k;i++){
			f[i]=i;
		}
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				e[++m].u=j;
				e[m].v=n+i;
				e[m].w=a[i][j];
			}
		}
		sort(e+1,e+m+1,cmp);
		int ans=0,cnt=0;
		for(int i=1;i<=m;i++){
			int fx=find(e[i].u);
			int fy=find(e[i].v);
			if(fx!=fy){
				f[fx]=fy;
				ans+=e[i].w;
				if(e[i].u<=n&&!vis[e[i].u]){
					vis[e[i].u]=true;
					++cnt;
				}
				if(e[i].v<=n&&!vis[e[i].v]){
					vis[e[i].v]=true;
					++cnt;
				}
			}
			if(cnt==n){
				printf("%lld",ans);
				break;
			}
		}
	}
	return 0;
}
