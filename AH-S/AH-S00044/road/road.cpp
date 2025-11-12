#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef struct Node{
	int to,val;
}Node;
vector<Node> v[10001];
int dis[10001],vis[10001];
int n,m,k,pos;
int ton[10001];
int city[15][10001];
void dijkstra();
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,f;
		cin>>x>>y>>f;
		v[x].push_back(Node{y,f});
		v[y].push_back(Node{x,f});
		ton[x]++;
		ton[y]++;
	}
	int maxn=0;
	for(int i=n+1;i>=n+k;i++){
		cin>>city[i][0];
		for(int j=1;j<=n;j++){
			cin>>city[i][j];
			v[j].push_back(Node{i,city[i][j]+city[i][0]});
		}
	}
	for(int i=1;i<=n;i++){
		if(ton[i]>maxn){
			maxn=ton[i];
			pos=i;
		}
	}
	dijkstra();
	/*int minn=INT_MIN;
	for(int i=1;i<=n;i++){
		minn=(minn,dis[i]);
	}
	cout<<minn<<'\n';
	*/
	cout<<dis[n]<<'\n';
	return 0;
}
void dijkstra(){
	queue<int> que;
	que.push(pos);
	dis[pos]=0;
	vis[pos]=1;
	while(!que.empty()){
		int u=que.front();
		que.pop();
		int len=v[u].size();
		for(int i=1;i<=len;i++){
			if(dis[v[u][i].to]>dis[u]+v[u][i].val){
				dis[v[u][i].to]=dis[u]+v[u][i].val;
				if(!vis[v[u][i].to]){
					que.push(v[u][i].to);
					vis[v[u][i].to]=1;
				}
			}
		}
	}
}
