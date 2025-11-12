#include <bits/stdc++.h>
#define int long long
#define M 1000005
#define N 10105
using namespace std;
int n,m,k;
int vis[N]; 
struct node{
	int w,x,y;
} nm[M],val[M],use[M];
int fa[N]; 
int find(int x){
	if(fa[x] == x){
		return fa[x];
	}return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x); y=find(y);
	fa[y]=x;
	return ;
}
bool cmp(node aa,node bb){
	return aa.w < bb.w; 
}
int lin[N]; 
int cnt;
int ans;
int a[15][N];
int c[15]; 
void check(){
	int cntt=0;
	for(int i=1;i<=k;++i) if(lin[i]) cntt++;
	if(cntt > k/2+1) return ;
	int res=0;
	int num=0;
	for(int i=1;i<=n+k;++i){
		fa[i]=i;
	}
	for(int i=1;i<=cnt;++i){
		num++; 
		use[num].w=val[i].w;
		use[num].x=val[i].x;
		use[num].y=val[i].y;
	}
	for(int i=1;i<=k;++i){
		if(lin[i] == 1){
			res+=c[i]; 
			for(int j=1;j<=n;++j){
				++num;
				use[num].w=a[i][j];
				use[num].x=n+i;
				use[num].y=j;
			}
		}
	}
	sort(use+1,use+num+1,cmp);
	for(int i=1;i<=num;++i){
		node x=use[i];
		int u=x.x, v=x.y;
		if(find(u) != find(v)){
			merge(u,v);
			res+=x.w;
		}
	}
	ans=min(ans,res);
	return ;
}
void dfs(int dep){
	if(dep == k+1){
		check();
		return ;
	}
	lin[dep]=1;
	dfs(dep+1);
	lin[dep]=0;
	dfs(dep+1);
	return ;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		fa[i]=i; 
	} 
	for(int i=1;i<=m;++i){
		int u,v,w; cin>>u>>v>>w;
		nm[i].w=w; nm[i].x=u; nm[i].y=v;
	}
	for(int i=1;i<=k;++i){
		cin>>c[i];
		for(int j=1;j<=n;++j){
			cin>>a[i][j]; 
		}
	}
	sort(nm+1,nm+m+1,cmp);
	for(int i=1;i<=m;++i){
		node x=nm[i];
		int u=x.x, v=x.y;
		if(find(u) != find(v)){
			merge(u,v);
			cnt++;
			val[cnt].w=x.w; val[cnt].x=x.x; val[cnt].y=x.y;
		}
	}
	ans=1e18; 
	dfs(1);
	cout<<ans<<'\n'; 
	return 0;
}
