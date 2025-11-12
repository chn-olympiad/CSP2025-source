#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

struct edge{
	int to,w;
};

int const N=1e6+5;
int n,m,k,x;
int j[N],u[N],v[N],a[N],c[15],dis[N];
vector<edge> g[N];
vector<int> f[10005];
bool vis[N];

void spfa(int st){
	queue<int> q;
	q.push(st);
	memset(dis,0x3f,sizeof(dis));
	vis[st]=1;
	dis[st]=0;
	while(!q.empty()){
		int h=q.front();
		q.pop();
		vis[h]=0;
		int p=g[h].size();
		for(int i=0;i<p;i++){
			edge e=g[h][i];
			if(dis[e.to]>dis[h]+e.w){
				dis[e.to]=dis[h]+e.w;
				if(!vis[e.to]){
					q.push(e.to);
					vis[e.to]=1;
				}
			}
		}
	}
	return ;
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u[i],&v[i],&j[i]);
		g[u[i]].push_back((edge){v[i],j[i]});
		g[v[i]].push_back((edge){u[i],j[i]});
	}
	/*
	for(int i=1;i<=m;i++){
		int p=g[i].size();
		for(int j=0;j<p;j++){
			cout<<g[i][j].to<<" "<<g[i][j].w<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=1;i<=k;i++){
		scanf("%d",&c[i]);
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
		}
	}
	spfa(1);
	int maxn=-1;
	for(int i=2;i<=n;i++) maxn=max(maxn,dis[i]);
	cout<<maxn;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
