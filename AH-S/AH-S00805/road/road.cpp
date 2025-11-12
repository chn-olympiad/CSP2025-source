#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N=10005,M=1e6+5;
struct info{
	int to;
	int w;
};
vector<info>edges[N];
vector<info>t[N];
int a[15][N],fa[N],cost[N];
int d[N][N];
struct edge{
	int u;
	int v;
	int w;
}e[M];
int findset(int x){
	if(fa[x]==x) return x;
	else  return fa[x]=findset(fa[x]);
}
bool cmp(edge a,edge b){
	return a.w<b.w;
}
int kruskal(){
	int res=0;
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int from=e[i].u,to=e[i].v,w=e[i].w;
		int p=findset(from),q=findset(to);
		if(p!=q){
			fa[p]=q;
			res+=w;
			t[from].push_back({to,w});
			t[to].push_back({from,w});
		}
	}
	return res;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		e[i]={x,y,z};
		edges[x].push_back({y,z});
		edges[y].push_back({x,z});
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	int ans=kruskal();
	cout<<ans;
	return 0;
}
