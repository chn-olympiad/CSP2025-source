#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
struct kkk{
	int x,y,w,id,pos;
}e[1000005],ed[500005];
int c[15],a[15][100005];
int ud[1000005],tot,cnt,ans=1e18;
int fa[200005],d[200005];
int findd(int x){
	if(x==fa[x])return x;
	return fa[x]=findd(fa[x]);
}
void unionn(int x,int y){
	x=findd(x),y=findd(y);
	if(x!=y){
		if(d[y]<d[x])swap(x,y);
		d[y]=max(d[y],d[x]+1);
		fa[x]=y;
	}
}
bool vis[15];
int check(){
//	cout<<"5456\n";
	for(int i=1;i<=n+k;i++)fa[i]=i,d[i]=1;
	int res=0;
//	cout<<cnt<<'\n';
	for(int i=1;i<=cnt;i++){
		if(!vis[ed[i].pos])continue;
		if(findd(ed[i].x)!=findd(ed[i].y)){
//			cout<<ed[i].w<<'\n';
			unionn(ed[i].x,ed[i].y);
			res+=ed[i].w;
//			cout<<ed[i].w<<" "<<ed[i].pos<<'\n';
		}
	}return res;
}
void dfs(int cur,int sum){
	if(cur==k+1){
		ans=min(ans,check()+sum);
		return;
	}vis[cur]=1;
	dfs(cur+1,sum+c[cur]);
	vis[cur]=0;
	dfs(cur+1,sum);
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i,d[i]=1;
	for(int i=1;i<=m;i++)cin>>e[i].x>>e[i].y>>e[i].w,e[i].id=i,e[i].pos=0;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++)cin>>a[i][j];
	}
	stable_sort(e+1,e+m+1,[](kkk x,kkk y){return x.w<y.w;});
	for(int i=1;i<=m;i++){
		if(findd(e[i].x)!=findd(e[i].y)){
			ud[++tot]=e[i].id;
			unionn(e[i].x,e[i].y);
		}
	}stable_sort(e+1,e+m+1,[](kkk x,kkk y){return x.id<y.id;});
	vis[0]=1;
	for(int i=1;i<=tot;i++)ed[++cnt]=e[ud[i]];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			ed[++cnt]=kkk{i+n,j,a[i][j],0,i};
		}
	}stable_sort(ed+1,ed+cnt+1,[](kkk x,kkk y){return x.w<y.w;});
	vis[0]=1;
	dfs(1,0);
	cout<<ans;
	return 0;
}
