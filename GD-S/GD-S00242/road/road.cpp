#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
typedef pair<int,int> PII;
const int N=1e4+114;/////////////////////////////////////////
const int M=1e6+114;
const int INF=0x7f7f7f7f7f7f7f7f;
//const int INF=0x7f7f7f7f;
const int K=15;
int n,m,k;
int ans=INF;
struct Edge{
	int w=0,to=0,nex=0;
}edge[5*M];
int head[N+K],cnt,newhead[N+K],newcnt;
void add_edge(int a,int to_b,int w){
	edge[++cnt].nex=head[a];
	edge[cnt].w=w;
	edge[cnt].to=to_b;
	head[a]=cnt;
}
void add_new_edge(int a,int to_b,int w){
	edge[++newcnt].nex=newhead[a];
	edge[newcnt].w=w;
	edge[newcnt].to=to_b;
	newhead[a]=newcnt;
}

int prim(){
	int anst=0;
	int dis[N]={};
	memset(dis,0x7f,sizeof(dis));
	priority_queue<PII,vector<PII>,greater<PII> >pq;
	bool vis[N]={};
	pq.push(make_pair(0,1));
	while(!pq.empty()){
		while(!pq.empty()){
			if(!vis[pq.top().second])break;
			pq.pop();
		}
		if(pq.empty())break;
		anst+=pq.top().first;
		int pos=pq.top().second;
		vis[pos]=1;
		pq.pop();
		for(int i=newhead[pos];i;i=edge[i].nex){
			int to=edge[i].to;
			int w=edge[i].w;
			if(!vis[to]&&dis[to]>w){
				dis[to]=w;
				pq.push(make_pair(w,to));
			}
		}
	}
	return anst;
}
void init_edge(){
	newcnt=cnt;
	for(int i=1;i<=n+k;i++){
		newhead[i]=head[i];
	}
}
int kroad[K][N];
int kw[K];
void solve(){
	
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=k;i++){
		cin>>kw[i];
		for(int j=1;j<=n;j++){
			cin>>kroad[i][j];
		}
	}
	
	for(int i=0;i<=(1<<k)-1;i++){
		init_edge();
		int anstt=0;
		if(i!=0)for(int j=1;j<=k;j++){
			if(i&(1<<(j-1))){
				anstt+=kw[j];
				for(int p=1;p<=n;p++){
					add_new_edge(n+j,i,kroad[j][p]);
					add_new_edge(i,n+j,kroad[j][p]);
				}
			}
		}
		anstt+=prim();
		ans=min(ans,anstt);
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	IOS
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	solve();
	return 0;
}
