#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+1e5+5;
int n,m,k,cnt;
long long c[15],a[15][N];
struct edge{
	int u,v;
	long long w;
}e[M],ee[M];
bool vis[15];
int fa[M];
int get(int x){
	if(fa[x]==x)return x;
	return fa[x]=get(fa[x]); 
}
long long ans=1e16,res;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void prim(){
	for(int i=1;i<=cnt+m;i++){
		int x=get(ee[i].u),y=get(ee[i].v);
		if(x!=y){
			res+=ee[i].w;
			fa[x]=y;
			if(res>=ans)return ; 
		}
	}
	return ;
}
void dfs(int u){
	if(u==k+1){
		res=cnt=0;
		memcpy(ee,e,sizeof e);
		for(int i=1;i<=k;i++){
			if(vis[i]){
				for(int j=1;j<=n;j++){
					cnt++;
					ee[cnt+m].u=j,ee[cnt+m].v=i+n;
					ee[cnt+m].w=a[i][j];
				}
//				cout<<"i="<<i<<" ";
				res+=c[i];
			}
		}
//		cout<<endl;
//		cout<<"res1="<<res<<" "; 
		if(res>=ans)return ;
		for(int i=1;i<=cnt+m;i++)fa[i]=i;
		sort(ee+1,ee+cnt+m+1,cmp);
		prim();
		ans=min(ans,res);
//		cout<<"res2="<<res<<" ";
//		cout<<"ans="<<ans<<" ";
//		cout<<endl; 
		return ;
	}
	vis[u]=1;
	dfs(u+1);
	vis[u]=0;
	dfs(u+1);
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
	}
	for(int i=1;i<=k;i++){
		scanf("%lld",&c[i]);
		for(int j=1;j<=n;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	dfs(1);
	printf("%lld",ans); 
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
13

*/
