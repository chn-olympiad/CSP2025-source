#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=1e4+100;
struct Node{
	int y,v;
	bool operator<(const Node A)const{
		return v<A.v;
	}
}node;
int n,m,k;
vector<Node> arr[N];
priority_queue<Node> q;
int dist[N];
int vis[N];
void dijkstra(int a){
	memset(dist,127,sizeof(dist));
	dist[a]=0;
	node.y=1;
	node.v=0;
	q.push(node);
	while(!q.empty()){
		node=q.top();
		q.pop();
		int x=node.y;
		if(vis[x]==1){
			continue;
		}
		vis[x]=1;
		for(int i=0;i<arr[x].size();i++){
			if(dist[arr[x][i].y]>arr[x][i].v+dist[x]){
				dist[arr[x][i].y]=arr[x][i].v+dist[x];
				node.y=arr[x][i].y;
				node.v=arr[x][i].v+dist[x];
				q.push(node);
			}
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	int u,v,w;
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&u,&v,&w);
		node.y=v;
		node.v=w;
		arr[u].push_back(node);
		node.y=u;
		node.v=w;
		arr[v].push_back(node);
	}
	int c;
	for(int i=1;i<=k;i++){
		scanf("%d",&c);
		node.y=i+n;
		node.v=c;
		for(int i=1;i<=n;i++){
			arr[i].push_back(node);
		}
		int a;
		for(int i=1;i<=n;i++){
			scanf("%d",&a);
			node.y=i;
			node.v=a;
			arr[i+n].push_back(node);
		}
	}
	dijkstra(1); 
	int ans=0;
	for(int i=1;i<=n;i++){
		if(dist[i]<0x3f3f3f3f){
//			cout<<dist[i]<<" ";
			ans=max(ans,dist[i]);
		}
	}
	cout<<ans;
	return 0;
}
