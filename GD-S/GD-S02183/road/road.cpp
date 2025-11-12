#include<bits/stdc++.h>
#define M 5000010
#define N 10010
using namespace std;
int c[22],a[22][N];
int n,m,k,fa[N],ans;
struct edge{
	int fr,to,w;
}e[M];
vector<edge> mst[N];
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int finda(int x){
	if(fa[x]==x)return x;
	return fa[x]=finda(fa[x]);
}
void merger(int x,int y){
	int fa1=finda(x),fa2=finda(y);
	fa[fa1]=fa2;
}
void kruskal(){
	for(int i=1;i<=m;i++){
		int x=e[i].fr,y=e[i].to,w=e[i].w;
		int fx=finda(x),fy=finda(y);
		if(fx!=fy){
			ans+=w;
			mst[x].push_back({x,y,w});
			mst[y].push_back({y,x,w});
			merger(x,y);
		}	
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		e[i].fr=u,e[i].to=v,e[i].w=w;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		int xs[N]={0},cnt=0;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(!a[i][j])xs[++cnt]=j;
		}
		for(int j=1;j<=cnt;j++){
			for(int x=1;x<=n;x++){
				if(xs[j]==x)continue;
				e[++m].fr=xs[j],e[m].to=x,e[m].w=a[i][x];
			}
		}
	}
	sort(e+1,e+m+1,cmp);
	kruskal();
	cout<<ans;
	return 0;
} 
