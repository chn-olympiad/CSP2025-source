#include<bits/stdc++.h>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
struct node{
	int v,w;
	operator <(const node &x) const{
        return x.w>w;
	}
};
struct edge{
	int num;
	int a[N];
}road[500];
vector<node> vc[N];
int n,m,k,dis[N],num[N],sum,maxx;
bool vis[N];

int dij(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	memset(num,0x3f,sizeof(num));
	priority_queue <node>q; 
	dis[s] = 0;
	q.push((node){s,0});
	while(!q.empty()){
		node t = q.top();
		q.pop();
		int u = t.v;
//		cout<<s<<" "<<u<<" "<<t.w<<endl;
		if(t.w>dis[u]||vis[u]) continue;
		vis[u] = 1;
		for(int i = 0;i<vc[u].size();i++){
			int v = vc[u][i].v;
//			printf("%d %d %d %d %d %d\n",u,v,i,dis[u],dis[v],vc[u][i].w);
			if(!vis[v]&&dis[u]+vc[u][i].w<dis[v]){
				num[v] = min(num[v],vc[u][i].w);
				dis[v] = dis[u]+vc[u][i].w;
//				printf("%d %d\n",num[v],dis[v]);
				q.push((node){v,dis[v]});
			}
		}
	}
 }

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		vc[x].push_back((node){y,z});
		vc[y].push_back((node){x,z});
	}
	dij(1);
	for(int i = 1;i<=n;i++){ maxx+=num[i];}
//	cout<<endl;
	if(k==0){
		cout<<maxx;
		return 0;
	}
	for(int i = n+1;i<=n+k;i++){
		cin>>road[i].num;
		for(int j = 1;j<=n;j++){
			int x;
			cin>>x;
			vc[i].push_back((node){j,x});
			vc[j].push_back((node){i,x});
		}
		if(road[i].num>maxx) continue;
		dij(i);	
		sum = 0;
		for(int j = 1;j<=n;j++){ sum+=num[j];}
		maxx = min(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
