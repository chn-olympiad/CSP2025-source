#include<bits/stdc++.h>
using namespace std;

//long long!!!!!!!!!!!!!!!!!!!!!!!!!!

int c[12][NINF];

int INF=1e6+5;
int NINF=1e4+15;

int head[NINF];
struct Edge{
	int v,nxt,w;
}e[2*INF];

int add_cnt=0;
void add(int u,int v,int w) {
	e[++add_cnt].v=v;
	e[add_cnt].w=w;
	e[add_cnt].nxt=head[u];
	head[u]=add_cnt;
}

struct Node{
	long long w;
	int n;
	bool operator<(Node x) const{
		x.w<w;
	}
};

long long f[NINF];
bool vis[NINF];



int main() {
//	freopen("road.in","r",stdin);
//	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(u,v,w);
	}
	for(int i=1;i<=k;i++) {
		scanf("%d",&c[i][0]);
		for(int j=1;j<=n;j++) {
			scanf("%d",&c[i][j]);
		}
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			for(int ii=1;ii<=k;ii++) {
				add(i,j,c[ii][0]+c[ii][i]+c[ii][j]);
				add(j,i,c[ii][0]+c[ii][i]+c[ii][j]);
			}
		}
	}
	
	for(int i=n+k;i>=0;i--) {
		f[i]=0x3f3f3f3f;
	}
	
	priority_queue<Node> p;
	p.push({0,1});
	
	while(!p.empty()) {
		int w=p.top().w;
		int nw=p.top().n;
		p.pop();
		if(vis[nw]==1) continue;
		vis[nw]=1;
		for(int i=head[nw];i!=0;i=e[i].nxt) {
			int v=e[i].v;
			if(vis[v]==0) {
				if(f[v]>f[u]+e[i].w) {
					p.push({f[u]+e[i].w,v});
					f[v]=f[u]+e[i].w;
				}
			}
		}
	}
	
	
	return 0;
}
