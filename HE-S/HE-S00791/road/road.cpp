#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+20;
typedef pair<int,int> p;
int n,m,k;
vector<p> a[N];
int vis[N];
int cost[15];
int flag=0;
int v[15];
priority_queue<p,vector<p>,greater<p> > q;
int krus(){
	int res=0;
	memset(vis,0,sizeof(vis));
	q.push(p(0,1));
	while(!q.empty()){
		int k=q.top().second;
		int val=q.top().first;
		q.pop();
		if(vis[k])continue;
		vis[k]=1;
		res+=val;
		for(auto mb:a[k]){
			int to=mb.first;
			int w=mb.second;
			if(vis[to]) continue;
			if(to>n&&v[to-n]==0) continue;
			q.push(p(w,to));
		}
	}
	return res;
}
int minn=1e16+7;
void dfs(int i,int c){
	if(i==k+1){
		int now=krus();
		minn=min(minn,now+c);
		return;
	}
	v[i]=0;
	dfs(i+1,c);
	v[i]=1;
	dfs(i+1,c+cost[i]);
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		a[u].push_back(p(v,w));
		a[v].push_back(p(u,w));
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		if(cost[i]) flag=1;
		for(int j=1,w;j<=n;j++){
			cin>>w;
			a[j].push_back(p(n+i,w));
			a[n+i].push_back(p(j,w));
		}
	}
	if(flag==0){// A
		for(int i=1;i<=k;i++){
			v[i]=1;
		}
		cout<<krus();
	}
	else{
		dfs(1,0);
		cout<<minn;
	}
	return 0;
}
