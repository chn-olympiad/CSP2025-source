#include<bits/stdc++.h>
#define M 3000006
#define N 20005
#define ll long long
using namespace std;
char st;
int n,m,k,fa[N],tot,a[15][N],c[N],vis[N];
struct edge{
	int u,v,w;
}e[M];
bool cmp(edge x,edge y){
	return x.w<y.w;
}
ll ans=1e18;
int fnd(int x){
	if(fa[x]!=x)fa[x]=fnd(fa[x]);
	return fa[x];
}
void dfs(int x,ll sum,int cnt1){
	if(x>k){
		int cnt=0;
		ll res=sum;
		for(int i=1;i<=n+k;i++)
			fa[i]=i;
		for(int i=1;i<=tot;i++){
			if(e[i].u>n&&!vis[e[i].u])continue;
			int fx=fnd(e[i].u),fy=fnd(e[i].v);
			if(fx!=fy){
				cnt++;
				res+=e[i].w;
				fa[fx]=fy;
			}
			if(cnt==n+cnt1-1)break;
		}	
		ans=min(ans,res);
		return;
	}
	vis[x+n]=1;
	dfs(x+1,sum+c[x],cnt1+1);
	vis[x+n]=0;
	dfs(x+1,sum,cnt1);
}
char ed;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[++tot]={u,v,w};
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]),e[++tot]={n+i,j,a[i][j]};
	}
	sort(e+1,e+tot+1,cmp);
	dfs(1,0,0);
	printf("%lld\n",ans);
}
