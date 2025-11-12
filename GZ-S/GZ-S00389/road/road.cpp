//GZ-S00389 北京师范大学贵阳附属中学 葛森蓥

#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
#define ll long long

struct Edge{
	int A,B;
	ll cost;
	bool operator<(const Edge other)const{
		return other.cost>cost;
	}
}deleting;
priority_queue<Edge>q;
struct Node{
	vector<int>to;
}city[1011];
int have_edge[1011];
bool graph[1011][1011],kind[1011]; //城市为0，表示必须在生成树中。乡村为1，表示可以不在生成树中
ll n,m,k,u,v,w,ac,ans,self_price[11];

bool vis[1011];
queue<int>bfs;
bool connected(int st){
	if(kind[st]){
		return 1;
	}
	memset(vis,0,sizeof vis);
	int cnt=1,now;
	vis[st]=1;
	while(!bfs.empty()){
		bfs.pop();
	}
	bfs.push(st);
	while(!bfs.empty()){
		cnt++;
		now=bfs.front();
		bfs.pop();
		for(int a=0;a<city[now].to.size();a++){
			if(!vis[city[now].to[a]] && graph[now][city[now].to[a]]){
				vis[city[now].to[a]]=1;
				bfs.push(city[now].to[a]);
			}
		}
	}
	return cnt==n;
} 

int main(){
	freopen("C:/Users/Administrator/Desktop/csps/down/road/road1.in","r",stdin);
	freopen("road.out","w",stdout);
	
	memset(kind,0,sizeof kind);
	cin>>n>>m>>k;
	for(int a=0;a<m;a++){
		cin>>u>>v>>w;
		have_edge[u]+=1;
		have_edge[v]+=1;
		graph[u][v]=1;
		graph[v][u]=1;
		city[u].to.push_back(v);
		city[v].to.push_back(u);
		q.push(Edge{u,v,w});
		ans+=w;
	}
	for(int a=m+1;a<=m+k;a++){
		cin>>self_price[a-m];
		kind[a]=1;
		for(int b=1;b<=n;b++){
			cin>>ac;
			have_edge[b]+=1;
			have_edge[a]+=1;
			graph[a][b]=1;
			graph[b][a]=1;
			city[b].to.push_back(a);
			city[a].to.push_back(b);
			q.push(Edge{a,b,self_price[a-m]+ac});
			ans+=(self_price[a-m]+ac);
		}
	}
	
	//删边
	while(!q.empty()){
		deleting = q.top();
		q.pop();
		if(connected(deleting.A)&&connected(deleting.B)){
			ans-=deleting.cost;
		}
		graph[deleting.A][deleting.B]=0;
		graph[deleting.B][deleting.A]=0;
		have_edge[deleting.A]--;
		have_edge[deleting.B]--;
	}
	for(int a=m+1;a<m+k;a++){
		if(have_edge[a]>=1){
			ans-=self_price[a-m]*(have_edge[a]-1);
		}
	}
	cout<<ans;
	return 0;
}
