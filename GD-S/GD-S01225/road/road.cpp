#include<bits/stdc++.h>
using namespace std;
long long n,m,k,fa[10010],f[10010][15],jp[10010][15],idx;
long long a[15][10010],c[10010],vis[10010];
long long val[10010],ans,dep[10010];
struct edge{
	long long u,v,w;
}b[1000010],t[1000010];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
bool cmp2(edge x,edge y){
	return x.w>y.w;
}
long long gf(long long x){
	if(fa[x]==x)return x;
	fa[x]=gf(fa[x]);
	return fa[x];
}
struct node{
	long long v,w;
};
vector<node>g[10010];
void DFS1(long long u,long long father){
	for(int i=0;i<g[u].size();i++){
		long long v=g[u][i].v,w=g[u][i].w;
		if(v==father)continue;
		val[v]=w;
		DFS1(v,u);
	}
}
void DFS(long long u,long long father){
	f[u][0]=father;
	for(int i=1;i<=15;i++)f[u][i]=f[f[u][i-1]][i-1];
	jp[u][0]=val[u];
	for(int j=1;j<=15;j++)
		jp[u][j]=max(jp[u][j-1],jp[f[u][j-1]][j-1]);
	dep[u]=dep[father]+1;
	for(int i=0;i<g[u].size();i++){
		long long v=g[u][i].v;
		if(v==father)continue;
		DFS(v,u);
	}
}
long long maxx(long long x,long long y){
	if(dep[x]<dep[y])swap(x,y);
	long long res=0;
	for(int i=15;i>=0;i--){
		if(dep[f[x][i]]>=dep[y])x=f[x][i],res=max(res,jp[x][i]);
	}
	if(x==y)return res;
	for(int i=15;i>=0;i--){
		if(f[x][i]!=f[y][i]){
			res=max(jp[x][i],max(res,jp[y][i]));
			x=f[x][i],y=f[y][i]; 
		}
	}
	res=max(res,max(jp[x][0],jp[y][0]));
	return res;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)scanf("%lld%lld%lld",&b[i].u,&b[i].v,&b[i].w);
	sort(b+1,b+m+1,cmp);
	for(int i=1;i<=m;i++){
		long long x=gf(b[i].u),y=gf(b[i].v);
		if(x!=y){
			fa[x]=y;
			g[b[i].u].push_back((node){b[i].v,b[i].w});
			g[b[i].v].push_back((node){b[i].u,b[i].w});
			t[++idx]=b[i];
			ans+=b[i].w;
		}
	}
	if(k==0){
		printf("%lld",ans);
		return 0;
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++)scanf("%lld",&a[i][j]);
	}
	DFS1(1,0);
	DFS(1,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			long long res=maxx(i,j),minn=1e18,pos=0;
			for(int z=1;z<=k;z++){
				if(vis[z]==1){
					if(minn>a[z][i]+a[z][j])minn=a[z][i]+a[z][j],pos=z;
				}
				else {
					if(minn>a[z][i]+a[z][j]+c[z])minn=a[z][i]+a[z][j]+c[z],pos=z;
				}
			}
			a[pos][i]=a[pos][j]=0;
			if(res>minn)ans+=minn-res;
		}
	}
	printf("%lld",-(ans)/2);
	return 0;
}
