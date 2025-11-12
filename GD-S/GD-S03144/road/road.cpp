#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5,M=1e6+5,K=15;
int n,m,k;
struct node{
	int u,v,w;
}e[M],h[M];
int head[N],to[M],nxt[M],val[M],cnt=0,ans=0;
int c[K],a[K][N];
int now[K],g[K];
int sum=0,mx=1e9;
int fa[N];
bool cmp(node x,node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void add(int x,int y,int z){
	cnt++;
	to[cnt]=y;
	val[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void fun(){
	//cerr<<'\n';
	int ans=sum,top=m;
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
	for(int i=1;i<=k;i++){
	//	cerr<<now[i]<<' ';
		if(now[i]){
			for(int j=1;j<=n;j++){
				top++;
				e[top].u=i+n,e[top].v=j,e[top].w=a[i][j];
			}
		}
	}
	//cerr<<'\n';
	sort(e+1,e+top+1,cmp);
	//for(int i=1;i<=top;i++)cerr<<e[i].u<<' '<<e[i].v<<'\n';
	for(int i=1;i<=top;i++){
		int x=e[i].u,y=e[i].v;
		int xx=x,yy=y;
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y,ans+=e[i].w/*,cerr<<xx<<' '<<yy<<'\n'*/;
	}
	//cerr<<'\n';
	//cerr<<sum<<' '<<ans<<'\n';
	for(int i=1;i<=m;i++)e[i]=h[i];
	mx=min(mx,ans);
	if(mx==0){
		cout<<mx;
		exit(0);
	}
}
void dfs(int x){
	if(x>k)fun();
	else{
		sum+=c[x];
		now[x]=1;
		dfs(x+1);
		sum-=c[x];
		now[x]=0;
		dfs(x+1);
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)cin>>e[i].u>>e[i].v>>e[i].w,h[i]=e[i];
	bool flag=0; 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		g[i]=c[i];
		if(c[i])flag=1;
		for(int j=1;j<=n;j++)cin>>a[i][j],flag=(flag||bool(a[i][j]));
	}
	if(k==0){
		for(int i=1;i<=n;i++)fa[i]=i;
		sort(e+1,e+m+1,cmp);
		int ans=0;
		for(int i=1;i<=m;i++){
			int x=e[i].u,y=e[i].v;
			int xx=x,yy=y;
			x=find(x),y=find(y);
			if(x!=y)fa[x]=y,ans+=e[i].w;
		}
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<mx;
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
*/
