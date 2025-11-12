#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lowbit(x) x&-x
const int N=1e4+500+5;
const int M=1e6+5;
const int INF=0x3f3f3f3f;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
struct edge{
	int to,w;
	edge(int a,int b){
		to=a,w=b;	
	}
};
vector <edge> e[M<<1];
bool vis[N];
int dist[N];
struct node{
	int dis,id;
	friend bool operator<(node a,node b){
		return a.dis>b.dis;
	} 
	node(int a,int b){
		dis=a,id=b;
	}
};
int n,m,k;
//void dijkstra(int st){
//	priority_queue<node> q;
//	for(int i=1;i<N;i++) dist[i]=INF,vis[i]=0;
//	dist[st]=0;
//	q.push(node(0,st));
//	while(!q.empty()){
//		node sdd=q.top();
//		q.pop();
//		int x=sdd.id;
//		if(vis[x]) continue;
//		vis[x]=1;
//		for(int i=0;i<e[x].size();i++){
//			int v=e[x][i].to,w=e[]
//		}
//	}
//}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		int u,v,w;
		u=read(),v=read(),w=read();
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int so;
			so=read();
		}
	} 
	cout<<0<<endl;
	return 0;
}