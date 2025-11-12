#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
int n,m,k,ans;
struct node{
	int id,dis;
	bool operator>(const node&other)const{
		return dis>other.dis;
	}
};
struct edge{
	int to,we;
};
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	vector<vector<edge> > mp(n+k+5);
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		mp[u].push_back({v,w});
		mp[v].push_back({u,w});
		ans+=w;
	}
	for(int i=1;i<=k;i++){
		int a1,a2,a3,a4,a5;
		cin>>a1>>a2>>a3>>a4>>a5;
	}
//	vector<int> d(n+k+5,INT_MAX);
//	vector<bool> vis(n+k+5,false);
//	priority_queue<node,vector<node>,greater<node> > q;
//	d[1]=0;q.push({1,0});
//	while(!q.empty()){
//		node nw=q.top();
//		q.pop();
//		int id=nw.id;
//		if(vis[id]) continue;
//		vis[id]=true;
//		for(edge c:mp[id]){
//			int v=c.to,w=c.we;
//			if(v!=id){
//				if(d[id]+w<d[v]){
//					d[v]=d[id]+w;
//					q.push({v,d[v]});
//				}
//			}
//			
//		}
//	}
	cout<<ans;
	return 0;
}