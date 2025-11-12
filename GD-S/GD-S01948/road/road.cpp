#include<bits/stdc++.h>
using namespace std;
const int M=3e6+10,N=1e4+10;
struct edge{
	int u,v;
	long long l;
}e[M],g[N];
int n,fa[N],k,m,cnt,sz[N],vis[N],tag[N];
long long ans,w,c[20];
unordered_map<int,long long> mp[N];
int find(int x){
	if(x==fa[x]){
		return x;
	}else{
		return fa[x]=find(fa[x]);
	}
}
bool cmp(edge x,edge y){
	return x.l<y.l;
}
void mer(int x,int y){
	int fx=find(x),fy=find(y);
	if(sz[fx]<sz[fy]){
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	}else{
		fa[fy]=fx;
		sz[fx]+=sz[fy];
	}
//	cout<<fx<<' '<<fy;
}
void kr(){
	for(int i=1;i<=m;i++){
		int x=e[i].u,y=e[i].v;
		long long tx=0,ty=0;
		if(tag[x]){
			if(vis[x])tx=c[x];
		}
		if(tag[y]){
			if(vis[y])ty=c[y];
		}
		if(find(x)!=find(y)){
			if(tag[x])vis[x]=1;
			if(tag[y])vis[y]=1;
			mp[x][y]=e[i].l-tx-ty;
			mp[y][x]=e[i].l-tx-ty;
			ans=ans+e[i].l-tx-ty;
		//	cout<<x<<' '<<y<<endl;
			mer(x,y);
		}
	}
	
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].l);
	}
	int h=n;
	for(int i=n+1;i<=n+k;i++){
		tag[i]=1;
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&w);
			++m;
			e[m].u=i;
			e[m].v=j;
			e[m].l=w+c[i];
		}
	}
	sort(e+1,e+m+1,cmp);
	
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
		sz[i]=1;
	}
	kr();
	for(int i=n+1;i<=n+k;i++){
		if(sz[i]==1){
			for(auto j:mp[i]){
				ans-=j.second;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}

