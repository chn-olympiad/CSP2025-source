#include<bits/stdc++.h>
#define int long long 
#define endl '\n'
using namespace std;
const int N=1e4+5,M=2*1e6+5;
int fa[N*2],c[15],d[15][N];
int u[M],v[M],w[M],minn=INT_MAX;
int n,m,k;
bool vis[15];
struct Node{
	int u,v,w;
}e[M];
bool cmp(Node x,Node y){
	return x.w<y.w;
}
int find(int x){
	if(fa[x]==0){
		return x;
	}
	fa[x]=find(fa[x]);
	return fa[x];
}
void dfs(int x){
	if(minn==0){
		return;
	}
	if(x>k){
		for(int i=1;i<=n+k;i++){
			fa[i]=0;
		}
		int cnt=0,sum=0;
		for(int i=1;i<=m;i++){
			e[++cnt]={u[i],v[i],w[i]};
		}
		for(int i=1;i<=k;i++){
			if(vis[i]==false)continue;
			sum+=c[i];
			for(int j=1;j<=n;j++){
				e[++cnt]={n+i,j,d[i][j]};
			}
		}
		sort(e+1,e+cnt+1,cmp);
		for(int i=1;i<=cnt;i++){
			int a=find(e[i].v);
			int b=find(e[i].u);
			if(a!=b){
				fa[a]=b;
				sum+=e[i].w;
			}
		}
		minn=min(minn,sum);
		return;
	}
	vis[x]=true;
	dfs(x+1);
	vis[x]=false;
	dfs(x+1);
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>d[i][j];
		}
	}
	dfs(1);
	cout<<minn<<endl;
	return 0;
}
