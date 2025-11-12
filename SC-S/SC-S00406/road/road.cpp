#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mp make_pair
#define N 10005
#define ll long long
#define inf 0x3f
int n,m,k,ans,c[15],a[15][N],fa[N],cnt,ecnt;
bool vixj[15];
map<pair<int,int>,int>xj;
map<pair<int,int>,int>ys;
struct node{
	int v,w;
};
struct edge{
	int u,v,w;
}e[N*200];
vector<node> vt[N];
int find(int x){
	return fa[x]==x?x:find(fa[x]);
}
inline void kruskal(){
	for(int i=1;i<=ecnt;i++){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)==find(v)) continue;
		ans+=w;
		fa[v]=u;
		cnt++;
		if(cnt==n-1) return ;
	}
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		vt[u].push_back({v,w});
		vt[v].push_back({u,w});
		e[++ecnt].u=u;
		e[ecnt].v=v;
		e[ecnt].w=w;
		e[++ecnt].u=v;
		e[ecnt].v=u;
		e[ecnt].w=w;
		ys[mp(u,v)]=ecnt-1;
		ys[mp(v,u)]=ecnt;
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
		for(int j=1;j<=n-1;j++){
			for(int k=j+1;k<=n;k++){
				if(!xj[mp(j,k)]){
					xj[mp(j,k)]=a[i][j]+a[i][k];
					if(ys[mp(j,k)]){
						e[ys[mp(j,k)]].w=min(e[ys[mp(j,k)]].w,xj[mp(j,k)]);
					}
					else{
						e[++ecnt].u=j;e[ecnt].v=k;e[ecnt].w=xj[mp(j,k)];
					}
					continue;
				}
				if(a[i][j]+a[i][k]<xj[mp(j,k)]){
					xj[mp(j,k)]=a[i][j]+a[i][k];
					if(ys[mp(j,k)]){
						e[ys[mp(j,k)]].w=min(e[ys[mp(j,k)]].w,xj[mp(j,k)]);
					}
					else{
						e[++ecnt].u=j;e[ecnt].v=k;e[ecnt].w=xj[mp(j,k)];
					}
				}
			}
		}
	}
	sort(e+1,e+1+ecnt,cmp);
	if(k>0){
		for(int i=1;i<=n;i++){
			for(int j=0;j<vt[i].size();i++){
				int v=vt[i][j].v,w=vt[i][j].w;
				if(xj[mp(i,v)]<w && xj[mp(i,v)]){
					vt[i][j].w=xj[mp(i,v)];
				}
			}
		}
	}
	kruskal();
	cout<<ans<<endl;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 1 3 2 4
*/