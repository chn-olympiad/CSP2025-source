#include<bits/stdc++.h>
#define ll long long
using namespace std;
int const N=1e4+20,M=1e6+20;
ll n,m,k;
ll c[11],a[11][N],mn[N][11],sum[(1<<10)];
bool vis[11];
struct Edge{
	ll u,v,w;
}edge[M];
bool cmp(Edge x,Edge y){
	return x.w<y.w;
}
int f[N];
int Find(int id){
	if(f[id]==id)return id;
	f[id]=Find(f[id]);
	return f[id];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	for(int i=1;i<N;i++)f[i]=i;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&edge[i].u,&edge[i].v,&edge[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&mn[j][i]);
		}
	}
	for(int i=0;i<(1<<k);i++){
		for(int j=1;j<=k;j++){
			if((1<<(j-1))&i)sum[i]+=c[j];
		}
	}
	sort(edge+1,edge+m+1,cmp);
	for(int i=1;i<=m;i++){
		Edge t=edge[i];
		int fu=Find(t.u),fv=Find(t.v);
		if(fu!=fv){
			for(int j=0;j<(1<<k);j++){
				ll s=1e18;
				for(int z=1;z<=k;z++){
					if((1<<(z-1))&j)s=min(s,min(t.w,mn[fu][z]+mn[fv][z]));
					else s=min(s,t.w);
				}
				sum[j]+=s;
				//cout<<sum[j]<<" ";
			}//cout<<endl;
			f[fu]=fv;
			for(int j=1;j<=k;j++)mn[fv][j]=min(mn[fv][j],mn[fu][j]);
		}
	}
	ll ans=1e18;
	for(int i=0;i<(1<<k);i++)ans=min(ans,sum[i]);
	printf("%lld",ans);
	return 0;
} 
