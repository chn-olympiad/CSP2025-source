#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct node{
	int u,v,w;
}a[1000010];
node b[1000005];
int c[1000005];
int edge[15][100001];
int vis[120];
int fa[100010];
int siz[1000010];
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	if(siz[x]>siz[y]) swap(x,y);
	fa[x]=y;
	siz[y]+=siz[x];
}
int ans=1e18;
void dfs(int now){
	if(now==k+1){
		int cnt=0;
		int tot=0;
		memset(b,0,sizeof(0));
		for(int i=1;i<=n+k;i++){
			siz[i]=1,fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			b[++tot]=a[i];
		}
		for(int i=1;i<=k;i++){
			if(!vis[i]) continue;
			cnt+=c[i];
			int u=n+i;
			for(int j=1;j<=n;j++){
				int v=j;
				int w=edge[i][j];
				b[++tot]={u,v,w};
			}
		}
		sort(b+1,b+1+tot,cmp);
		for(int i=1;i<=tot;i++){
			int x=b[i].u,y=b[i].v,w=b[i].w;
			int xx=find(x),yy=find(y);
			if(xx==yy) continue;
			cnt+=w;
			merge(xx,yy);
		}
		ans=min(ans,cnt);
		return;
	}
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			siz[i]=1,fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			a[i]={u,v,w};
		}
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=a[i].u,y=a[i].v,w=a[i].w;
			int xx=find(x),yy=find(y);
			if(xx==yy) continue;
			ans+=w;
			//cout<<w<<" ";
			merge(xx,yy);
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			siz[i]=1,fa[i]=i;
		}
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			a[i]={u,v,w};
		}
		for(int i=1;i<=k;i++){
			cin>>c[i];//起点
			for(int j=1;j<=n;j++){
				cin>>edge[i][j];
			}
		}
		dfs(1);//深搜考虑取不取
		sort(a+1,a+1+m,cmp);
		for(int i=1;i<=m;i++){
			int x=a[i].u,y=a[i].v,w=a[i].w;
			int xx=find(x),yy=find(y);
			if(xx==yy) continue;
			ans+=w;
			//cout<<w<<" ";
			merge(xx,yy);
		}
		cout<<ans;
	}
	
	return 0;
}
/*
5 6 0
1 2 1
2 4 4
2 3 100
3 4 100
4 5 7
3 5 8
*/
