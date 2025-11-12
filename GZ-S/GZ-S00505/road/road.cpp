//GZ-S00505 »ÆÎÄÌÎ 
//Coding for T2. Road
#include<bits/stdc++.h>
//think 1.kruskal
//think 2.kruskal
//noticed that k is really small.
//so why not.
#define us unsigned
#define xll long long
#define ull us long long
#define MAXN (ull)1e4+17
//#define PII pair<int,int>
//#define mkpr(a,b) make_pair(a,b)
//#define q1 first
//#define q2 second
using namespace std;
struct edg{
	int u,v,w;
	
	bool operator>(const edg &other) const{
		return w>other.w;
	}
};
priority_queue<edg,vector<edg>,greater<edg> > e;
int head[MAXN];
int vilcost[15];
int n,m,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.in","r",stdin);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		e.push({u,v,w});
		//e.push({v,u,w});
	}
	for(int i=1;i<=k;i++){
		cin>>vilcost[i];
		for(int j=1;j<=n;j++){
			int w;
			cin>>w;
			e.push({n+i,j,w});
			//e.push({j,n+i,w});
		}
	}
	int ans=0;
	//for(int i=1;i<=n+k+1;i++) head[i]=i;
	array<bool,MAXN> vis;
	vis.fill(false);
	int siz=0;
	while(siz!=n){
		//cout<<e.top().u<<" to "<<e.top().v<<" with w= "<<e.top().w<<endl;
		edg edge=e.top();
		e.pop();
		//cout<<"u head"<<fndhead(edge.u)<<" with v head"<<fndhead(edge.v)<<endl;
		//head[fndhead(edge.u)]=fndhead(edge.v);
		if((!vis[edge.u]||!vis[edge.v])) {
			if(!vis[edge.u]) siz++;
			if(!vis[edge.v]) siz++;
			vis[edge.u]=true;
			vis[edge.v]=true;
		}
		ans+=edge.w;
	}
	//for(int i=n+1;i<=n+k;i++) if(vis[i]) ans+=vilcost[i-n];
	cout<<ans+1<<endl;
	return 0;
}
