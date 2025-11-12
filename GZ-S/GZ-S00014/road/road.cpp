// GZ-S00014 代玲聪 安顺市第一高级中学 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define max(a,b) (a>b?a:b)
#define ll long long
#define INF 0x7fffffff
using namespace std;
const int N=1e6+10;
/*inline int in(){
	char ch=getchar();
	int w=1,s=0;
	while(ch>'9'||ch<'0'){
		if(ch=='-')w*=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}*/
int h[N],dis[N],cost[N];
bool vis[N];
int n,m,cnt,k;
struct edge{
	int to,next,val;
	
}e[N*2];
void add(int u,int v,int w){
	cnt++;
	e[cnt].to=v;
	e[cnt].val=w;
	e[cnt].next=h[u];
	h[u]=cnt;
}
struct node{
	int v,w;
	friend bool operator < (node a,node b){
		return a.w>b.w; 
	} 
}tmp;
priority_queue<node> q;
void Dijkstra(int s){
	for(int i=1;i<=m;i++){
		dis[i]=INF;
	}
	dis[s]=0;
	tmp.v=s,tmp.w=0;
	q.push(tmp);
	while(!q.empty()){
		int u=q.top().v;
		q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=h[u];i;i=e[i].next){
			if(dis[e[i].to]>dis[u]+e[i].val){	
			dis[e[i].to]=dis[u]+e[i].val;
			tmp.v=dis[e[i].to],tmp.w=e[i].to;q.push(tmp);
			}
		}
		
	}
} 
int ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		add(u,v,w);
		add(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin >> cost[i];
		for(int j=1;j<=n;j++){
		int tmp;
			cin >> tmp;
			add(n+i,j,tmp);
			add(j,n+i,tmp);
		}
	}
	Dijkstra(1);
	cout << dis[n] << endl;
	return 0;
	
}
