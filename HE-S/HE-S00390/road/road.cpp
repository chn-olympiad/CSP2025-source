#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std;
const int maxm=1000006;
const int maxn=10004;
const int maxk=15;
struct E{
	int to;
	int w;
	int nxt;
}edge[maxm*2];
int c[maxk];
int cnt;
int head[maxn];
int head_old[maxn];
int cnt_old;
void add(int from,int to,int w){
	edge[cnt].nxt=head[from];
	edge[cnt].to=to;
	edge[cnt].w=w;
	head[from]=cnt;
	++cnt;
}
int n,m,k;
struct comp{
	bool cmp(int &i,int &j){
		return edge[i].w>edge[j].w;
	}
};
int prim(){
	bool vis[maxn]={};
	int cnt=0;
	int ans=0;
	priority_queue<PII,vector<PII>,greater<PII> > q;
	q.push(make_pair(0,0));
	while(cnt!=n){
		PII tmp=q.top();
		int length=tmp.first;
		int u=tmp.second;
		q.pop();
		if(vis[edge[u].to]) continue;
		ans+=edge[u].w;
		if(edge[u].to>=1 && edge[u].to<=n){
			++cnt;
		}
		vis[edge[u].to]=true;
		for(int v=head[edge[u].to];v;v=edge[v].nxt){
			q.push(make_pair(edge[v].w,v));
		}
	} 
	return ans;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	add(0,1,0);
	for(int i=0,u,v,w;i<m;++i){
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,w);
	}
	int ans=prim();
	for(int i=1;i<=k;++i){
		cnt_old=cnt;
		for(int j=0;j<=n+i;++j){
			head_old[j]=head[j];
		}
		cin>>c[i];
		for(int j=1;j<=n;++j){
			int tmp;
			cin>>tmp;
			add(n+i,j,tmp);
			add(j,n+i,tmp);
		}
		int tmp=prim();
		if(ans>=tmp+c[i]){
			ans=tmp+c[i];
		}else{
			cnt=cnt_old;
			for(int j=0;j<=n+i;++j){
				head[j]=head_old[j];
			}
		}
	}
	cout<<ans;
}
