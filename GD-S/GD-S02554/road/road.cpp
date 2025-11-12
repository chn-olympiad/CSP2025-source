#include<bits/stdc++.h>
#define i64 long long
using namespace std;

const int N=1e4+50,M=1e6+20;

struct edge{int u,v,w,tag,nxt;}e[M*3];
struct Edge{int u,v,w,nxt;}e2[M],e3[M];
struct node{
	int id,v;
	i64 w;
	bool operator<(const node &o)const{return w>o.w;}
};
struct Node{
	int u,v;
	i64 w;
	bool operator<(const Node &o)const{return w>o.w;}
};

int n,m,k,cnt,cnt2;
i64 ans;
int a[15],c[15][N],vis[N],deg[N];
int head[N],h[N],h2[N];

priority_queue<node>q;

void add(int u,int v,int w){
	e[++cnt]={u,v,w,0,head[u]};
	head[u]=cnt;
}
void add2(int u,int v,int w){
	e2[++cnt2]={u,v,w,h[u]};
	h[u]=cnt2;
}
void prim(){
	i64 res=0;
	q.push({0,1,0});
	while(!q.empty()){
		node tp=q.top();
		q.pop();
		int t=tp.id,u=tp.v,d=tp.w;
		if(vis[u])continue;
		if(t)e[t].tag=1;
		vis[u]=1;
		res+=d;
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			q.push(node{i,v,w});
		}
	}
	ans=res;
	for(int i=1;i<=cnt;i++)if(e[i].tag){
		add2(e[i].u,e[i].v,e[i].w);
		add2(e[i].v,e[i].u,e[i].w);
	}
}
priority_queue<Node>q2;
int fa[N];
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
void kruscal(i64 x){
//	cout<<x<<endl;
	i64 res=x;
	for(int i=1;i<=n+k;i++)fa[i]=i;
	for(int i=1;i<=cnt2;i++){
//		cout<<":"<<e2[i].u<<' '<<e2[i].v<<' '<<e2[i].w<<endl;
		q2.push(Node{e2[i].u,e2[i].v,e2[i].w});
	}
//	cout<<"OK"<<endl;
	int num=1;
	while(!q2.empty()){
		Node tp=q2.top();
		int u=tp.u,v=tp.v,w=tp.w;
//		cout<<u<<' '<<v<<' '<<w<<endl;
		q2.pop();
		u=find(u);v=find(v);
		if(u==v)continue;
//		cout<<u<<' '<<find(u)<<' '<<v<<' '<<find(v)<<' '<<w<<endl;
		fa[u]=v;
		num++;
		res+=w;
		if(res>ans)return;
	}
//	cout<<":"<<x<<' '<<res<<endl;
	ans=min(ans,res);
}
void check(int x){
	i64 sum=0;
	for(int i=1;i<=k;i++){
		if(x&(1<<(i-1))){
			sum+=a[i];
			for(int j=1;j<=n;j++){
//				cout<<":"<<i+n<<' '<<j<<' '<<c[i][j]<<endl;
				add2(i+n,j,c[i][j]);
				add2(j,i+n,c[i][j]);
			}
		}
	}
	if(sum>ans)return;
	kruscal(sum);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	prim();
	for(int i=1;i<=k;i++){
		cin>>a[i];
		for(int j=1,x;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(int i=1,cnt3;i<(1<<k);i++){
		for(int j=1;j<=cnt2;j++)e3[j]=e2[j];
		for(int j=1;j<=n;j++)h2[j]=h[j];
		cnt3=cnt2;
		check(i);
		for(int j=1;j<=cnt2;j++)e2[j]=e3[j];
		for(int j=1;j<=n;j++)h[j]=h2[j];
		cnt2=cnt3;
	}
	cout<<ans;
	return 0;
}
/*
4 6 3
1 2 4
1 3 9
1 4 7
2 3 5
2 4 8
3 4 6
1 1 1 100 100
2 100 100 2 1
100 1 1 1 1

13
*/
