#include <bits/stdc++.h>
#define maxn 1200005
#define int long long
using namespace std;
struct node{
	int u,v,w,o;
	bool friend operator <(node a,node b){
		return a.w<b.w;
	}
}g[maxn];
int n,m,k,cnt,ans,fa[maxn],val[maxn];
int find(int x){
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool id[maxn];
void sol(){
	int sum=0;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=k;i++) if(id[i]) sum+=val[i];
	for(int i=1;i<=m;i++){
		if(!id[g[i].o]) continue;
		int u=find(g[i].u),v=find(g[i].v);
		if(u==v) continue;
		fa[u]=v;
		sum+=g[i].w;
	}
	ans=min(ans,sum);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int u,v,w;
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w;
		g[++cnt]={u,v,w,0};
	}
	for(int i=1;i<=k;i++){
		cin>>val[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			g[++cnt]={i+n,j,w,i};
		}
	}
	sort(g+1,g+cnt+1);
	n+=k,m=0;
	for(int i=1;i<=cnt;i++){
		u=find(g[i].u),v=find(g[i].v);
		if(u==v) continue;
		if(g[i].o==0) fa[u]=v;
		g[++m]=g[i];
	}
	id[0]=1;
	ans=0x3f3f3f3f3f3f3f3f;
	int p=k;
	while(p){
		sol();p=k;
		while(p!=0&&id[p]==1) id[p--]=0;
		id[p]=1;
	}
	cout<<ans;
	cout.flush();
	fclose(stdin);
	fclose(stdout);
}
