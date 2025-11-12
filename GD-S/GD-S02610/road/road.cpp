//48
#include<bits/stdc++.h>
using namespace std;
const int N=10005;
struct node{
	int u,v,w;
}e[N*110];
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m,k;
int fa[N];
int c[N];
int a[N][N];
int vis[N];
void init(){
	for(int i=1;i<=n;i++)	fa[i]=i;
}
int find(int x){
	if(x==fa[x])	return fa[x];
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if(x>y)	swap(x,y);
	fa[y]=x;
}
void solve(){
	cin>>n>>m>>k;
	init();
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			for(int k=1;k<=j-1;k++){
				e[++m].u=j;
				e[m].v=k;
				e[m].w=a[i][j]+a[i][k];
			}
		}
	}
	sort(e+1,e+1+m,cmp);
	int cnt=0,ans=0;
	for(int i=1;i<=m;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v))	continue;
		merge(u,v);
		ans+=e[i].w;
		cnt++;
		if(cnt==n-1){
			break;
		}
	}
	cout<<ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
}
