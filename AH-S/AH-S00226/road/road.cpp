#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct edge{
	int u,v,w;
}e[5000005];
int h[5000005];
int tot;
/*
void add(int u,int v,int w){
	e[++tot]={v,w,head[u]};
	head[u]=tot;
}
*/
int c[1005];
int a[15][10005];
int fa[10005];
int find(int x){
	return fa[x]=fa[x]==x?x:find(fa[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
long long ans;
bool tong[100000];
void kruskal(){
	sort(e+1,e+1+m+tot,cmp);
	//e[0]={0,e[1].u,0,1};
	int cnt=0;
	//for(int i=1;i<=m+tot;i++) {cout<<e[i].op<<" ";}
	for(int i=1;i<=m+tot;i++) {
		int tmp1=e[i].u;
		int tmp2=e[i].v;
		if(find(tmp1)!=find(tmp2)) {
			fa[tmp1]=tmp2;
			ans+=e[i].w;
			if(tmp1>=1&&tmp1<=n&&tong[tmp1]==0) cnt++,tong[tmp1]=1;
			if(tmp2>=1&&tmp2<=n&&tong[tmp2]==0) cnt++,tong[tmp2]=1;
		}
		if(cnt==n) break;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		e[i]={u,v,w};
	}
	e[++tot+m]={0,1,0};
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) {
			cin>>a[i][j];
		}
	}
	for(int i=1;i<n;i++) {
		for(int j=i+1;j<=n;j++) {
			int minn=INT_MAX;
			for(int v=1;v<=k;v++) {
				minn=min(minn,a[v][i]+a[v][j]);
				
			}
			e[++tot+m]={i,j,minn};
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	kruskal();
	cout<<ans;
	return 0;
}
