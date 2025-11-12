#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+10;
int n,m,k;
struct Node{
	int to,w,vil,p;
	Node(int a,int b,int c,int d){
		to=a,w=b,vil=c,p=d;
	}
};
struct com{
	bool operator()(Node a,Node b)const{
		return a.w>b.w;
	}
};
struct vill{
	int a[N],c,mn;
}vil[15];
int ans[1024];
void dfs(int dep,int sum,int S){
	if(dep>k){
		//cout<<S<<' '<<sum<<'\n';
		ans[S]=sum;
		return;
	}
	dfs(dep+1,sum+vil[dep].c+vil[dep].mn,S|(1<<(dep-1)));
	dfs(dep+1,sum,S);
}
vector<Node>G[N];
bool vis[N][1024];

void prim(int s){
	priority_queue<Node, vector<Node> ,com >q;
	q.push(Node(s,0,0,0));
	while(!q.empty()){
		Node p=q.top();
		q.pop();
		int to=p.to,w=p.w,vi=p.vil,la=p.p;
	//	cout<<to<<' '<<w<<' '<<vi<<' '<<la<<'\n';;
		if(vis[to][vi])continue;
		ans[vi]+=w;
		vis[to][vi]=1;
		for(int i=0;i<G[to].size();i++){
			int nt=G[to][i].to,nw=G[to][i].w,p=G[to][i].p,lt=G[to][i].p;
			if(lt==0){
				q.push(Node(nt,nw,vi,0));
			}
		}
		
			
	}
	int realans=1e18;
	for(int i=0;i<=(1<<k)-1;i++){
		//cout<<ans[i]<<' ';
		realans=min(realans,ans[i]);
	}
	cout<<ans[0];
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		G[u].push_back(Node(v,w,0,0));
		G[v].push_back(Node(u,w,0,0));
	}
	
	for(int i=1;i<=k;i++){
		
		cin>>vil[i].c;int mn=1e18,id;
		for(int j=1;j<=n;j++){
			cin>>vil[i].a[j];
			if(vil[i].a[i]<mn){
				mn=vil[i].a[j],id=j;
			}
		}
	//	cout<<id<<'\n';
		for(int p=1;p<=n;p++){//cout<<i<<'\n';
			if(p==id)continue;
			int w=vil[i].a[p];
			G[id].push_back(Node(p,w,0,i));
			G[p].push_back(Node(id,w,0,i));
		}
		vil[i].mn=mn;//cout<<i<<' ';
	}dfs(1,0,0);
	prim(1);
	return 0;
}
