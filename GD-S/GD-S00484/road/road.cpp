#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,o,fa[11005],sz[11005],c[15],cnt,ans=1e18;
pair<int,int>ww[110005],w2[110005];
struct ee{int u,v,w;friend bool operator<(const ee&a,const ee&b){return a.w<b.w;}}e1[1000005],e2[15][10005];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void dfs(int u,int w){
	for(int i=1;i<=n+k;i++)fa[i]=i,sz[i]=1;
	int res=w;
	for(int i=1;i<=cnt;i++){
		int p=ww[i].first,q=ww[i].second;
		int fx=find(e2[p][q].u),fy=find(e2[p][q].v);
		if(fx==fy)continue;if(sz[fx]>sz[fy])swap(fx,fy);
		fa[fx]=fy,sz[fy]+=sz[fx];res+=e2[p][q].w;
	}
	ans=min(ans,res);if(u==k+1)return;
	dfs(u+1,w);
	int i=1,j=1,tot=0;
	while(i<=cnt&&j<=n){
		int p1=ww[i].first,q1=ww[i].second;
		int p2=u,q2=j;
		if(e2[p1][q1].w<=e2[p2][q2].w)w2[++tot]=ww[i],i++;
		else w2[++tot]={u,j},j++;
	}
	while(i<=cnt)w2[++tot]=ww[i],i++;while(j<=n)w2[++tot]={u,j},j++;
	cnt=tot;for(int i=1;i<=cnt;i++)ww[i]=w2[i];
	dfs(u+1,w+c[u]);tot=0;
	for(int i=1;i<=cnt;i++)if(ww[i].first<u)w2[++tot]=ww[i];
	cnt=tot;for(int i=1;i<=cnt;i++)ww[i]=w2[i];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e1[i].u>>e1[i].v>>e1[i].w;
	sort(e1+1,e1+m+1);
	for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
	for(int i=1;i<=m;i++){
		int fx=find(e1[i].u),fy=find(e1[i].v);
		if(fx==fy)continue;
		if(sz[fx]>sz[fy])swap(fx,fy);fa[fx]=fy,sz[fy]+=sz[fx];e2[0][++o]=e1[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>e2[i][j].w,e2[i][j].u=n+i,e2[i][j].v=j;
		sort(e2[i]+1,e2[i]+n+1);
	}
	for(int i=1;i<=o;i++)ww[++cnt]={0,i};
	dfs(1,0),cout<<ans;
}
