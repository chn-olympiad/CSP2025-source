#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=10010;
const int inf=1e9;
int n,m,k;
struct Edge
{
	int u,v,w;
	int con;
}g[N*4];
int cnt=0;

void adde(int u,int v,int w,int p){
	cnt++;
	g[cnt].u=u;
	g[cnt].v=v;
	g[cnt].w=w;
	g[cnt].con=p;
}
int fa[N];
int findr(int x){
	return x==fa[x]?x:fa[x]=findr(fa[x]);
}

void merge(int x,int y){
	x=findr(x),y=findr(y);
	fa[x]=y;
}

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

int dist[N][N];
void Floyd(){
	for(int p=1;p<=n+k;p++)
		for(int i=1;i<=n+k;i++)
			for(int j=1;j<=n+k;j++)
				dist[i][j]=min(dist[i][j],dist[i][p]+dist[p][j]);
}

int a[20][N],c[20];

bool used[15];
int Kruskal(){
	int ans=0;
	int l=0;
	sort(g+1,g+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		int xr=findr(g[i].u),yr=findr(g[i].v);
		if(xr!=yr){
			if(g[i].con!=0&&!used[g[i].con]){
				ans+=c[g[i].con];
				used[g[i].con]=true;
			}
			ans+=g[i].w;
			l++;
			merge(xr,yr);
		}
		if(l==n-1){
			return ans;
		}
	}
	return -1;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++){
		for(int j=1;j<=n;j++)
			dist[i][j]=inf;
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		dist[x][y]=dist[y][x]=min(dist[x][y],z);
		//adde(y,x,z);
	}

	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(j==1) dist[j][n+i]=dist[n+i][j]=min(dist[n+i][j],a[i][j]+c[i]);
			else dist[j][n+i]=dist[n+i][j]=min(dist[n+i][j],a[i][j]);

		}
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	Floyd();
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i==j) continue;
			if(dist[i][j]!=inf)
				adde(i,j,dist[i][j],0);
		}
	}
	for(int i=1;i<=m;i++){
		g[i].w=dist[g[i].u][g[i].v];
	}
	cout<<Kruskal()<<'\n';

	return 0;
}