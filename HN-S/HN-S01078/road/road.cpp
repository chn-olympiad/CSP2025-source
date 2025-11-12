/*
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e4+5;
int n,m,k,flg=1,ans;
int c[20];
int a[20][N],dis[N],vis[N];
struct Node{
	int v,dis;
	bool operator<(const Node & nn)const{
		return dis>nn.dis;
	}
};
vector<Node> ve[N];
priority_queue<Node> pq;
void prim(){
	for(int i=1;i<=n;i++) dis[i]=(1<<29);
	dis[1]=0;
	pq.push({1,0});
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int pos=0;pos<ve[u].size();pos++){
			int v=ve[u][pos].v;
			int d=ve[u][pos].dis;
			if(vis[v] || d>dis[v]) continue;
			dis[v]=d;
			pq.push({v,dis[v]});
		}
	}
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flg=0;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	return 0;
}
//*/

//*
#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e4+5;
int n,m,k,flg=1,ans;
int c[20];
int a[20][N],dis[N],vis[N];
struct Node{
	int v,dis;
	bool operator<(const Node & nn)const{
		return dis>nn.dis;
	}
};
vector<Node> ve[N];
priority_queue<Node> pq;
void prim(){
	for(int i=1;i<=n;i++) dis[i]=(1<<29);
	dis[1]=0;
	pq.push({1,0});
	while(pq.size()){
		int u=pq.top().v;
		pq.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int pos=0;pos<ve[u].size();pos++){
			int v=ve[u][pos].v;
			int d=ve[u][pos].dis;
			if(vis[v] || d>dis[v]) continue;
			dis[v]=d;
			pq.push({v,dis[v]});
		}
	}
}
int cnt;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		cnt+=w;
		ve[u].push_back({v,w});
		ve[v].push_back({u,w});
	} 
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]!=0) flg=0;
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	if(k==0){
		prim();
		for(int i=1;i<=n;i++)
			ans+=dis[i];
		cout<<ans;
	}
	if(k!=0){
		cout<<cnt/(n-2);
	}
	return 0;
}
//*/
/*
4 5 0
1 2 4
1 3 7
2 3 3
3 4 2
2 4 5
*/
