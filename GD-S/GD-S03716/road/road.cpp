#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
const int M=2e6+10;
int n,m,k;
int fa[N];
int ans;
int c[N];
struct edge{
	int u;
	int v;
	int w;
}a[M];
int len;
bool cmp(edge x,edge y){
	return x.w<y.w;
}
void init(){
	for(int i=1;i<=n+k;i++){
		fa[i]=i;
	}
}
int find(int x){
	if(fa[x]==x)return x;
	else{
		fa[x]=find(fa[x]);
		return fa[x];
	}
}
int fns;
int vis[N];
void merge(int x,int y,int z){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		if(vis[x]&&x>n)z-=c[x];
		if(vis[y]&&y>n)z-=c[y];
		if(!vis[x]&&x<=n)fns++,vis[x]=1;
		if(!vis[y]&&y<=n)fns++,vis[y]=1;
		if(!vis[x]&&x>n)vis[x]=1;
		if(!vis[y]&&y>n)vis[y]=1;
		ans+=z;
		fa[fx]=fy;
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[++len].u=x;
		a[len].v=y;
		a[len].w=z;
	}
	for(int i=1;i<=k;i++){
		cin>>c[n+i];
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			a[++len].u=n+i;
			a[len].v=j;
			a[len].w=c[n+i]+x;
		}
	}
	sort(a+1,a+len+1,cmp);
	for(int i=1;i<=len;i++){
		int x=a[i].u;
		int y=a[i].v;
		int z=a[i].w;
		merge(x,y,z);
		if(fns==n)break;
	}
	cout<<ans;
	return 0;
}
