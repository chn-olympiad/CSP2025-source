#include <bits/stdc++.h>
#include <queue>
using namespace std;
int n,m,k,ans=0;
int head[10000],dis[10001], vc[10001][10001];
bool visited[10001];
int cut=1;
queue<int> q;
struct state{
	int to;
	int wight;
	int next;
}edge[10001];
void add(int s,int e,int w){
	edge[cut].to=e;
	edge[cut].wight=w;
	edge[cut].next=head[cut];
	head[s]=cut;
	cut++;
}
int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	memset(dis,sizeof(dis), 0xfffff);
	dis[1] = 0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) {
		int s, e, w;
		cin>>s>>e>>w;
		add(s,e,w);
		add(e,s,w);
	}
	for(int i=1;i<=m;i++) for(int p=0;p<=n;p++) cin>>vc[i][p];
	q.push(1);
	while(!q.empty()) {
		int s = q.front();
		q.pop();
		visited[s]=1;
		for(int i = head[s];i!=0;i=edge[i].next){
			if(dis[edge[i].to] > dis[s] + edge[i].wight) {
				dis[edge[i].to] = dis[s] + edge[i].wight;
				q.push(edge[i].to);
			}
		}
	}
	for(int i=1;i<=n;i++)ans+=dis[i];
	cout<<ans<<endl;
	return 0;
}
