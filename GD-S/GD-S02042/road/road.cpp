#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+30;
int n,m,k,c[N],d[N],vis[N],ys[N],ys_1[N],vis_ans[N],opn[N],ans,f[N];
vector<pair<int,int> >v[N];
vector<int> e[N];
priority_queue<pair<int,int> >q;
void dfs(int fa,int x){
	for(int i=0;i<e[x].size();i++){
		int son=e[x][i];
		if(son==fa) continue;
		ans+=abs(d[x]-d[son]);
		dfs(x,son);
	}
	return ;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,V,w;
		cin>>u>>V>>w;
		v[u].push_back({V,w});
		v[V].push_back({u,w});
	}
	//cout<<"??";
	for(int i=m+1;i<=m+k;i++){
		int w;
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>w;
			v[i].push_back({j,w});
			v[j].push_back({i,w});
		}
	}
	memset(d,0x3f3f,sizeof d);
	d[1]=0;
	q.push({0,1});
	while(q.size()){
		int fa=q.top().first,x=q.top().second;
		q.pop();
		if(vis[x]==1) continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++){
			int nxt=v[x][i].first,w=v[x][i].second;
			if(nxt==fa) continue;
			if(d[x]+w<d[nxt]){
				d[nxt]=d[x]+w;
				f[nxt]=x;
				q.push({x,nxt});
			}
		}
	}
	//dfs(0,1);
	//for(int i=1;i<=n+k;i++) cout<<d[i]<<" ";
	for(int i=1;i<=n+k;i++) if(f[i]!=0) ans+=abs(d[f[i]]-d[i]);
	for(int i=n+1;i<=n+k;i++){
		if(f[i]==0) continue;
		for(int j=1;j<=n;j++) if(f[j]==i) ys[i]=1;
		if(ys[i]) ans-=abs(d[f[i]]-d[i]);
		else ans+=c[i];
	}
	cout<<ans;
	return 0;
}/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
