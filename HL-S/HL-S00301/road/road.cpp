#include<bits/stdc++.h>
#define IO(x) freopen(#x ".in","r",stdin); freopen(#x ".out","w",stdout);
#define MAXN 11000
using namespace std;
struct Edge{
	int to,nxt,dis;
}G[MAXN*2];
struct Node{int to,nxt;};
int cnt=0,Book[MAXN],Head[MAXN*2],vis[MAXN*2];
void Add(int x,int y,int w){
	G[++cnt]=(Edge){y,Head[x],w};
	Head[x]=cnt;
}
int n,m,k,C[MAXN],A[MAXN][110],d[MAXN];
priority_queue<pair<int,int>>Q;
void dijkstra(int s){
	memset(d,0x3f,sizeof(d));
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	d[s]=0;
	Q.push({s,0});
	while(!Q.empty()){
		int x=Q.top().first;
		Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=Head[x];i;i=G[i].nxt){
			int y=G[i].to;
			if(d[y]>d[x]+G[i].dis){
				d[y]=d[x]+G[i].dis;
				Q.push({-d[y],y});
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	memset(Head,-1,sizeof(Head));
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		Add(x,y,z);
		Add(y,x,z);
	}
	dijkstra(1);
	for(int i=1;i<=n;i++)cout << d[i] << " ";
	return 0;
}


/**/
